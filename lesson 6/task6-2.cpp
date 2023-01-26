#include <iostream>
#include <cmath>
class Logarithm {
 private:
  double base, argument;
 public:

  double doubleValue();
  Logarithm(double inputBase, double inputArgument);
};

int main(){
    Logarithm lg(2,8);
    std::cout<<lg.doubleValue()<<std::endl;
}

double Logarithm::doubleValue() {
  try{
        if(this->base<=0){throw(1);}
        else if(this->base==1){throw(2);}
        else if(this->argument<=0){throw(3);}
        return log(this->argument) / log(this->base);
    }
    catch(int code){
        if(code==1){std::cout<<"Base is a negative number\n";}
        if(code==2){std::cout<<"Base is 1\n";}
        if(code==3){std::cout<<"Argument is a negative number\n";}
        
    }
}
Logarithm::Logarithm(double inputBase, double inputArgument) {
    
  this->base = inputBase;
  this->argument = inputArgument;
    
}