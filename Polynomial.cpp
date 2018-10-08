#include "Polynomial.h"

Polynomial::Polynomial(std::vector<double> coefficients):degree(coefficients.size()){
        for (auto&& item: coefficients)
            this->coefficients.push_back(item);
    }

    double Polynomial::getFunctionValue(double x){  //count value of polynomial for x
        double value=coefficients[0];
        for(uint32_t i=1; i<degree; ++i){
            value+=coefficients[i]*getPower(x,i);
        }
        return value;
    }

    double Polynomial::getRootInRange(double bottom, double top, double approx, int max){//secant method
        double root, firstValue, secondValue, rootValue;
        double firstPt=bottom;
        double secondPt=top;
        firstValue=getFunctionValue(firstPt);
        secondValue=getFunctionValue(secondPt);
        if( firstValue*secondValue>0){      //check if range is correct for secant method
            throw std::runtime_error("wartosci wielomianu w granicach musza miec rozne znaki");
        }
        for( ; max>0; --max ){
            root=firstPt-firstValue*(firstPt-secondPt)/(firstValue-secondValue);
            rootValue=getFunctionValue(root);
            if (fabs(rootValue)<approx){    //check if root is good enough
                if (root>top || root<bottom)
                    throw std::runtime_error("funkca nie moze posiadac ekstremum lokalnego w podanym przedziale");//sometimes if there is an extremum algorithm fails and return root which is not in range
                return root;
            }
            secondPt=firstPt;
            secondValue=firstValue;
            firstPt=root;
            firstValue=rootValue;

        }
        throw std::runtime_error("nie udalo sie odnalezc pierwiastka w zadanej ilosci literacji");
    }

    void Polynomial::printRootFromRange(double bottom, double top, double approx, int max){
        try{
            std::cout<<getRootInRange(bottom, top, approx, max)<<std::endl;
        }catch (const std::runtime_error& error){
            std::cout<<error.what()<<std::endl;
        }

    }

    double Polynomial::getPower(double base, uint32_t exponent){
        double result=1;
        for(uint32_t i=0; i<exponent; ++i){
            result*=base;
        }
        return result;
    }
//
// Created by Martyna on 08.05.2017.
//

