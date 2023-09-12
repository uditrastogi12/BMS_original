#include<iostream>
#include<string.h>
#include <regex>
using namespace std;
bool isBalance(float b)
{
    if (b>=5000)
    return true;
    else
    return false;

}
bool isNameValid(char a[])
{
    int len = strlen(a);
    for(int i=0 ; i<len ; i++)
    {
    if( (a[i]>=65 && a[i]<=90 ) || (a[i]>=97 && a[i]<=122  ))
    continue;
    else
    return false;
    }
    return true;
}


bool isValidPanCardNo(string panCardNo)
{
 
    // Regex to check valid
    // PAN Card number.
    const regex pattern("[A-Za-z]{5}[0-9]{4}[A-Za-z]{1}");
    
    // for(int i=0;i<5;i++)
    // {
    //     if(panCardNo[i]<65 || panCardNo[i]>90 && )
    // }
    // If the PAN Card number
    // is empty return false
    if (panCardNo.empty()) {
        return false;
    }
 
    // Return true if the PAN Card number
    // matched the ReGex
    if (regex_match(panCardNo, pattern))
    {
        
        return true;
    }
    else
    {
        return false;
    }
}


bool isValidAadhaarNumber(string str)
{
 
  // Regex to check valid Aadhaar number.
  const regex pattern("^[2-9]{1}[0-9]{3}\\s[0-9]{4}\\s[0-9]{4}$");
 
  // If the Aadhaar number
  // is empty return false
  if (str.empty())
  {
     return false;
  }
 
  // Return true if the Aadhaar number
  // matched the ReGex
  if(regex_match(str, pattern))
  {
    return true;
  }
  else
  {
    return false;
  }
}



bool isValidMobileNumber(string s)
{
   
  const regex pattern("(0|91)?[6-9][0-9]{9}");
 
 
  if(regex_match(s, pattern))
  {
    return true;
  }
  else
  {
    return false;
  }
}
