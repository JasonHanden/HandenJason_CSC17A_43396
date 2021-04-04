
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 3, 2021, 6:40 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct MonthlyBudget{
    float house=500.00;
    float util=150.00;
    float houseEx=65.00;
    float transp=50.00;
    float food=250.00;
    float med=30.00;
    float insur=100.00;
    float enter=150.00;
    float clothes=75.00;
    float misc=50.00;
};
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
MonthlyBudget input(MonthlyBudget);
void print(MonthlyBudget);
void eval(float,float);
void total(MonthlyBudget,MonthlyBudget);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    
    //Initialize Variables
    MonthlyBudget expense;
    //Process or map Inputs to Outputs
    expense=input(expense);
    //Display Outputs
    print(expense);
    //Exit stage right!
    return 0;
}

MonthlyBudget input(MonthlyBudget expense){
    cout<<"Enter housing cost for the month:$\n";
    cin>>expense.house;
    cout<<"Enter utilities cost for the month:$\n";
    cin>>expense.util;
    cout<<"Enter household expenses cost for the month:$\n";
    cin>>expense.houseEx;
    cout<<"Enter transportation cost for the month:$\n";
    cin>>expense.transp;
    cout<<"Enter food cost for the month:$\n";
    cin>>expense.food;
    cout<<"Enter medical cost for the month:$\n";
    cin>>expense.med;
    cout<<"Enter insurance cost for the month:$\n";
    cin>>expense.insur;
    cout<<"Enter entertainment cost for the month:$\n";
    cin>>expense.enter;
    cout<<"Enter clothing cost for the month:$\n";
    cin>>expense.clothes;
    cout<<"Enter miscellaneous cost for the month:$\n";
    cin>>expense.misc;
    
    return expense;
}
void print(MonthlyBudget expense){
    MonthlyBudget budget;
    
    cout<<"Housing"; eval(expense.house,budget.house);
    cout<<"Utilities"; eval(expense.util,budget.util);
    cout<<"Household Expenses"; eval(expense.houseEx,budget.houseEx);
    cout<<"Transportation"; eval(expense.transp,budget.transp);
    cout<<"Food"; eval(expense.food,budget.food);
    cout<<"Medical"; eval(expense.med,budget.med);
    cout<<"Insurance"; eval(expense.insur,budget.insur);
    cout<<"Entertainment"; eval(expense.enter,budget.enter);
    cout<<"Clothing"; eval(expense.clothes,budget.clothes);
    cout<<"Miscellaneous"; eval(expense.misc,budget.misc);
    
    cout<<"You were $";
    total(expense,budget);
}
void eval(float spent,float budget){
    if(int(spent*100)>int(budget*100)){
        cout<<" Over\n";
    }else if(int(spent*100)<int(budget*100)){
        cout<<" Under\n";
    }else if(int(spent*100)==int(budget*100)){
        cout<<" Even\n";
    }
}
void total(MonthlyBudget expense, MonthlyBudget budget){
    float totExp=0,totBdgt=0,diff=0;
    string output;
    
    totExp+=expense.clothes;
    totExp+=expense.enter;
    totExp+=expense.food;
    totExp+=expense.house;
    totExp+=expense.houseEx;
    totExp+=expense.insur;
    totExp+=expense.med;
    totExp+=expense.misc;
    totExp+=expense.transp;
    totExp+=expense.util;
    
    totBdgt+=budget.clothes;
    totBdgt+=budget.enter;
    totBdgt+=budget.food;
    totBdgt+=budget.house;
    totBdgt+=budget.houseEx;
    totBdgt+=budget.insur;
    totBdgt+=budget.med;
    totBdgt+=budget.misc;
    totBdgt+=budget.transp;
    totBdgt+=budget.util;
    
    diff=totBdgt-totExp;
    if(int(diff*100)<0){
        output=" over budget";
        diff*=-1;
    }else if(int(diff*100)>0){
        output=" under budget";
    }else if(int(diff*100)==0){
        output=" under budget";
    }
    cout<<fixed<<setprecision(2)<<diff<<output;
}