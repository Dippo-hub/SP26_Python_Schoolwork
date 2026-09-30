#include <iostream>
#include <string>
using std::string;

class Stock {
    private:
        string symbol, company;
        double prevClosingPrice, currentPrice;

    public:
        Stock(const string &symbol, const string &company) {
            this->symbol = symbol;
            this->company = company;
            prevClosingPrice = 0.0;
            currentPrice = 0.0;
        }

        void getStocks() {
            std::cout << company << "(" << symbol << ") previously closed at " << prevClosingPrice << " and is currently at " << currentPrice << " (change " << getChangePercent() << "%)" << std::endl;
        }

        void setPrices(double prev, double cur) {
            if (prev>0 && cur>0) {
                prevClosingPrice = prev;
                currentPrice = cur;
            } else {
                std::cout << "Both values must be greater than 0." << std::endl;
            }
        }

        double getChangePercent() {
            return ((currentPrice - prevClosingPrice) / prevClosingPrice) * 100;
        }
};

int main(void) {
    Stock n("NVDA", "NVIDIA Corp");
    n.setPrices(27.5, 27.6);
    n.getStocks();
}