// Problem Link : https://www.codingninjas.com/studio/problems/beautiful-string_1115625

int makeBeautiful(string str) {
	// Write your code here
	int c1 = 0 ; 
	int c2 = 0 ; 

	for(int i = 0 ; i<str.length() ;i++){
		if(i&1 && str[i]=='1'){
			c1++ ;
		}

		if(i%2==0 && str[i]=='0'){
			c1++ ;
		}

		if(i&1 && str[i] == '0'){
			c2++ ;
		}

		if(i%2==0 && str[i]=='1'){
			c2++ ;
		}
	}

	return min(c1 , c2) ;
}