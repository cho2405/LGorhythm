class Solution {
public:
    int dp(string s, int* arr) {
        int size = s.size();
        int sum = 0;
        
        if(s[0] == '0') return 0;
        
        int num = atoi(s.c_str());
        if(arr[size] != -1) return arr[size];
        if (num == 10 || num == 20) return arr[size] = 1;
        if ((num >=11 && num <=26) || s=="") {
            cout << "!!" <<endl;
            return arr[size] = 2;
        }
        if ((num >=1 && num <10) ) return arr[size] = 1;
        for(int i = 1; i <= 2; i++){
            cout << "!!" <<endl;    
            if(s.substr(size-i, i).c_str()[0] == '0') continue;
            int intValue = atoi(s.substr(size-i, i).c_str());
            
            cout << "intValue:" << intValue << endl;
            if ( intValue >= 1 && intValue <= 26) {
                cout << s.substr(0, size-i) << endl;
                sum += dp(s.substr(0, size-i), arr);   
            }else if(intValue==0) return arr[size] = 0;
            
        }
        return arr[size] = sum;
    }
    int numDecodings(string s) {
        int size = s.size();
        int * arr = new int[size+1];
        cout << size << endl;
        for (int i = 0; i<size+1; i++) {
            arr[i] =-1;        }
        int sum = dp(s, arr);
        return sum;
    }
};
