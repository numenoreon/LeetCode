class Solution{
	public:

		string validateV4(string & IP, int count) {
			if (count != 3)
				return "Neither";
            count=0;
			stringstream ss;
			ss << IP;
			string temp;
			int tempInt = 0;
                    
			while (ss>>temp) {
                ++count;
                
                if(temp[0]=='0' && temp.size()>1)
                    return "Neither";
                
                if(temp.size()>3)
                    return "Neither";
                
				for (int i = 0; i < temp.size(); ++i) {
					if (!isdigit(temp[i]))
						return "Neither";
				}

					tempInt = stoi(temp);
				if (tempInt < 0 || tempInt > 255)
					return "Neither";
			}
            
			return count == 4 ? "IPv4" : "Neither";
		}

		string validateV6(string & IP, int count) {

			if (count != 7)
				return "Neither";
            count = 0;
            
			stringstream ss;
			ss << IP;

			string temp;
			while (ss >> temp) {
                ++count;
				if (temp == "")
					return "Neither";

                if (temp.size() > 4)
		            return "Neither";
                
                for(int i=0; i<temp.size(); ++i){
                    if(!isdigit(temp[i]) && temp[i]!='a' && temp[i]!='b' && temp[i]!='c' && temp[i]!='d' &&
                            temp[i]!='e' && temp[i]!='f' && temp[i]!='A' && temp[i]!='B' && temp[i]!='C' &&
                            temp[i]!='D' && temp[i]!='E' && temp[i]!='F')
                        return "Neither";
                }
	        
            if (temp == string(temp.size(), '0'))
		        continue;
	    
	        }   
        cout << count;
	    return count == 8 ? "IPv6" : "Neither";
	    }

	string validIPAddress(string IP) {
		int count1 = 0, count2 = 0;

		for (int i = 0; i < IP.size(); ++i) {
			if (IP[i] == '.') {
				++count1;
				IP[i] = ' ';
			}
			else if (IP[i] == ':') {
				++count2;
				IP[i] = ' ';
			}
		}

		if (count1 > 0 && count2 > 0)
			return "Neihter";
		else if (count1 > 0)
			return validateV4(IP, count1);
		else if (count2 > 0)
			return validateV6(IP, count2);

		return "Neither";
	}

};