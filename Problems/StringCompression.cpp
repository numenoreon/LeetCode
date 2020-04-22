class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 1, write = 0, counter=1;
        char last = chars[0];
        
        while(read<chars.size()){
            if(chars[read]==last){
                ++counter, ++read;
            }
            else if(chars[read]!=last){
                chars[write++]=last;
                last=chars[read++];
                if(counter>1){
                    string temp = to_string(counter);
                    int s=0;
                    while(s<temp.length()){
                        chars[write++]=temp[s++];
                    }
                }
                counter=1;
            }
        }

        chars[write++]=last;
        if(counter>1){
            string temp = to_string(counter);
            int s=0;
            while(s<temp.length()){
                chars[write++]=temp[s++];
            }
        }

        return write;
    }
};