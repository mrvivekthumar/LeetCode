class Solution {
public:
    int nthUglyNumber(int n) {
      vector<int> arr(n+1);
      
      int i2, i3, i5;
      
      i2 = i3 = i5 = 1;
      
      arr[1] = 1;
      
      for(int i = 2; i<= n ;i++){
        
        int i2Ugly = arr[i2]*2;
        int i3Ugly = arr[i3]*3;
        int i5Ugly = arr[i5]*5;
        
        int minimum = min({i2Ugly,i3Ugly,i5Ugly});
        
        arr[i] = minimum;
        
        if(i2Ugly == minimum){
            i2++;
        }
        if(i3Ugly == minimum){
            i3++;
        }
        if(i5Ugly == minimum){
            i5++;
        }
      }
      return arr[n]; 
    }

    
    // BRUTE  FORCE
    
    // bool isUgly (int n){
    //     while(n > 1){   
    //         if( n % 2 == 0){
    //             n /= 2;            
    //         }
    //         else if ( n % 3 == 0){
    //             n /= 3; 
    //         }
    //         else if ( n % 5 == 0){     
    //         n /= 5;  
    //         }
    //         else{
    //             return false;  
    //         }
    //     }
    //     return true;
    // }

    // int nthUglyNumber(int n) {
    //     int cnt = 1;

    //     if( n ==1 ){
    //         return 1;
    //     }

    //     int i = 2;

    //     while(true){
    //         bool var = isUgly(i);
    //         if(var == true){
    //             cnt++;
    //         }
    //         if(cnt == n){
    //             break;
    //         }
    //         i++;
    //     }
    //     return i;   
    // }
};