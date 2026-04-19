import os
from dotenv import load_dotenv
from langchain_google_genai import GoogleGenerativeAIEmbeddings
load_dotenv()
embeddings = GoogleGenerativeAIEmbeddings(model="models/gemini-embedding-001")
vector1 = embeddings.embed_query("dog")
vector2 = embeddings.embed_query("puppy")
print(f"These are the vectors: {vector1}")
print(f"These are the vectors: {vector2}")
