// Problem link : https://leetcode.com/problems/fraction-to-recurring-decimal/

string fractionToDecimal(int numerator, int denominator) {
    if(numerator==0){
        return "0" ; 
    }
    string s= ((numerator<0)^(denominator<0))? "-" : "" ; 
    long long num = abs(static_cast<long long>(numerator)) ; 
    long long den = abs(static_cast<long long>(denominator)) ; 

    string res1 = to_string(num/den) ; 
    string res2 = (num%den) ? "." : "" ; 
    string res3 = "" ; 
    unordered_map<long long , int>mp ;
    long long rem = num%den ; 
    while(rem!=0){
        if(mp.find(rem)!=mp.end()){
            res3.insert(mp[rem], "(") ; 
            res3+=")" ; 
            break ;
        }
        mp[rem]= res3.size() ; 
        rem*=10 ; 
        res3+=to_string(rem/den); 
        rem%=den ; 
    }
    return s+res1+res2+res3 ; 
}