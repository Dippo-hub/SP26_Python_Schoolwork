from dotenv import load_dotenv
from langchain_core.prompts import ChatPromptTemplate
from langchain_google_genai import ChatGoogleGenerativeAI
from langgraph.checkpoint.sqlite import SqliteSaver
from langgraph.graph import StateGraph, add_messages
from typing import Annotated
from typing_extensions import TypedDict
 
load_dotenv()

class State(TypedDict):
    messages: Annotated[list, add_messages]


class StateMachine:
    def __init__(self, memory):
        model = ChatGoogleGenerativeAI(model="gemini-2.5-flash")
 
        system_prompt = ChatPromptTemplate.from_messages([
            ("system",
             """You are an expert advisor at a Crypto Finance Bank.
             The bank's name is Yenbase. Your name is Changpeng.
             You advise users on the three crypto loan products:
             1/ Short term loan, 6 month duration, 23% interest, up to BTC 10000.
             2/ Mid-term loan, 24 month duration, 15% interest, up to BTC 20000.
             3/ Long-term loan, 60 month duration, 9% interest, up to BTC 50000.
             Only respond to user questions on these loans."""),
            ("placeholder", "{messages}"),
            ("human", "{input}"),
        ])
 
        sp_function = system_prompt | model

        def chat_agent(state: State):
            return {"messages": [sp_function.invoke(state["messages"])]}
        
        graph_builder = StateGraph(State)
        graph_builder.add_node("chat_agent", chat_agent)
        graph_builder.set_entry_point("chat_agent")
        graph_builder.set_finish_point("chat_agent")
 
        self.thread = {"configurable": {"thread_id": "2"}}
        self.chain = graph_builder.compile(checkpointer=memory)

    def respond(self, USER_MESSAGE: str):
        result = self.chain.invoke(
            {"messages": ("user", USER_MESSAGE)},
            self.thread
        )
        # pretty_repr prepends an "=== AI Message ===" banner — trim it
        return result["messages"][-1].pretty_repr()[80:]

with SqliteSaver.from_conn_string(":memory:") as memory:
    chat_agent = StateMachine(memory)
    chat_agent.chain.get_graph().print_ascii()   # visualize the graph
    print("Agent will keep chatting until you say 'STOP' or 'QUIT'")
    user_question = ""
    while user_question.upper().strip() not in ["STOP", "QUIT", "EXIT"] and user_question != "":
        try:
            user_question = input("User: ")
            answer = chat_agent.respond(user_question)
            print("Agent: " + answer)
        except KeyboardInterrupt:
            print("\nChat interrupted by user.")
            break
        except EOFError:
            print("\nEnd of input detected. Exiting chat.")
            break

