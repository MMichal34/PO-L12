#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>
#include <string>

class FakeCantor {
 private:
  std::map<std::string, float> rates{{"USD", 1.0366f},
                                     {"GBP", 0.87063f},
                                     {"CHF", 0.9881f},
                                     {"JPY", 145.12f}};
 public:
  FakeCantor() = default;
  float EuroToRate(const std::string &currency) {
    return rates[currency];
  };
};

class Currency {
 public:
  virtual Currency *AddedCurrency(float value, std::string currency) = 0;
  virtual Currency *SubtractedCurrency(float value, std::string currency) = 0;
  virtual std::string Abbreviation() = 0;
  virtual std::string Symbol() = 0;
  virtual std::string Balance() = 0;
  virtual float DollarExchangeRate() = 0;
};

class Euro : public Currency {
  float amount;
  FakeCantor cantor;
  public:
  Euro(float am): amount(am){};
  Euro * AddedCurrency(float value, std::string currency) override {
      Euro * neweur = new Euro(amount+value*(1/cantor.EuroToRate(currency)));
      return neweur;
  };
  Euro * SubtractedCurrency(float value, std::string currency) override{
    if(amount-value*(1/cantor.EuroToRate(currency))>=0){
    Euro * neweur = new Euro(amount-value*(1/cantor.EuroToRate(currency)));
      return neweur;
    }
    else{std::cout<<"After operation you would have less than 0 euro."<<std::endl;
        return this;
    }
  };

  std::string Abbreviation() override{
    return "EUR";
  };

  std::string Symbol() override{
   return "€";
  };

  std::string Balance() override{
    return  std::to_string(amount);
  };
  float DollarExchangeRate() override{
     return cantor.EuroToRate("USD");
  };


};

int main() {
  Euro * money = new Euro(100.0f);
  std::cout<<money->Balance()<<std::endl;
  money = money->AddedCurrency(100.0f,"JPY");
  std::cout<<money->Balance()<<std::endl;
  money = money->SubtractedCurrency(200.0f,"JPY");
  std::cout<<money->Balance()<<std::endl;
  money = money->AddedCurrency(100.0f,"JPY");
  std::cout<<money->Balance()<<std::endl;
  std::cout<<money->Abbreviation()<<std::endl;
  std::cout<<money->Symbol()<<std::endl;
  std::cout<<money->DollarExchangeRate()<<std::endl;
  return 0;
}
