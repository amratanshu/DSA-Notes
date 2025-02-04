https://www.fastprep.io/problems/amazon-similar-text-substring-count

Amazon reviews and text written by people in the search - matching.

Fixed size Sliding window ->

class Solution {
public:
  int similarTextSubstringCount(string key, string text) {

    int text_length = text.length();
    int key_length = key.length();
    
    int ans = 0;

    for(int i=0;i<=text_length-key_length;i++){
      int k = 0;
      bool swapped = false;
      while(k<key_length){
        if(text[i+k]==key[k]) k++; 
        else{
          if(!swapped){
            swap(text[i+k],text[i+k+1]);
            swapped = true;
            if(text[i+k]==key[k]) k++;
          }
          else break;
        }
      }
      
      if(k==key_length) ans++;
      }

    return ans;
    }
};