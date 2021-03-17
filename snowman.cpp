#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <array>

const int Zero=0,One=1,Two=2,Three=3,Four=4,Five=5,Six=6,Seven=7,Eight=8,Nine=9,Ten=10;

//This function checks  input is legal
void legalDigit(int n){
   string numToString= std::to_string(n);
    int numLen= numToString.length();
    //Check if range is between 1 and 4 
    for(int i=Zero; i<numLen; i++){
        if(numToString[i]< '1' || numToString[i]>'4'){
            throw std::out_of_range(" Error ...The range  has to be between 1 to 4 \n");
        }
    }

    //Check that  length of the number is  8
  
    if(numLen != Eight){
        throw std::out_of_range("Error ...length is not legal it has to be 8 ,\n");
    }

}
 
string hat( int x){
    if(x==One){
      return "_===_" ;
    }
    if (x==Two)
    {
        return " ___ \n.....";
    }
    if(x==Three)
    {
    
        return "_\n  /_\\" ;
    }

    if(x==Four){
        return "___\n (_*_)";
     }
     return "";
    
}

string face(int l,int r,int n){
  array<std::string,Four> Eyes={".", "o", "O","-"};
  array<std::string,Four> noses={",", ".", "_"," "};
  return "("+Eyes.at(l-One)+noses.at(n-One)+Eyes.at(r-One)+")";
}

string body(int leArm,int t ,int RiArm){

  array<std::string,Five>LArm={"<","\\","/"," ",""};
  array<std::string,Five>RArm={">","/","\\"," ",""};
  array<std::string,Four>Torso={" : ", "] [", "> <","   "};
  return LArm.at(leArm-One)+"("+Torso.at(t-One)+")"+RArm.at(RiArm-One);
}

string base(int x){
   if(x==One){
      return"( : )" ;
    } 
    if (x==Two)
    {
        string str="(";
        str=str+"\" \"";
        str=str+")";
        return str;
    }
    if(x==Three)
    {
    
        return "(___)";
    }

    if(x==Four){
        return "(   )";
     }
     
     return "";  
}

string snowman1(int  num){
    
    int subnum =Zero;
    while(num>Zero){
      subnum=subnum*Ten+num%Ten;
      num=num/Ten;
    }
    num=subnum;
    int h=num%Ten;
    num=num/Ten;
    string theman=hat(h)+'\n';
    int nose=num%Ten;
    num=num/Ten;
    int le=num%Ten;
    num=num/Ten;
    int r=num%Ten;
    num=num/Ten;
    int leftarm=num%Ten;
    num=num/Ten;
    int rightarm=num%Ten;
    num=num/Ten;
    int torso=num%Ten;
    num=num/Ten;
    if(leftarm!=Two&&rightarm!=Two)
    {
        theman=theman+face(le,r,nose)+'\n';
        theman=theman+body(leftarm,torso,rightarm)+'\n';    
    }
    else if(leftarm==Two && rightarm!=Two){
        theman=theman+"\\"+face(le,r,nose)+'\n';
        theman=theman+body(Five,torso,rightarm)+'\n';
    }
    else if(leftarm!=Two && rightarm==Two){
        theman=theman+face(le,r,nose)+"/"+'\n';
        theman=theman+body(leftarm,torso,Five)+'\n';
    }
    else{
        theman=theman+"\\"+face(le,r,nose)+"/"+'\n';
        theman=theman+body(Five,torso,Five)+'\n';
    }
    int b=num%Ten;
    theman=theman+base(b);
return  theman;
}

namespace ariel {

    string snowman(int str){      

        legalDigit(str);
        return snowman1(str);

    }
}







