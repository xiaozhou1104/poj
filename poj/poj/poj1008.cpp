#include <iostream>
#include <string>

using namespace std;


string haab_month[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
					"zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

string holly_name[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", 
						"muluk", "ok", "chuen","eb", "ben", "ix", "mem", "cib", "caban", 
						"eznab", "canac", "ahau"};

int main(){

	int nums;
	cin>>nums;
	cout<<nums<<endl;
	int day,month,year,total_days;
	int holly_year, holly_month, holly_day;
	char temp;
	string str_month;
	for(int i=0; i<nums; i++){
		cin>>day>>temp>>str_month>>year;
		for(int j=0; j<19; j++){
			if(str_month == haab_month[j]){
				month = j+1;
				break;
			}
		}
			
		if(month != 19){
			total_days = 365*year + day+1 + (month-1)*20;
		}
		else{
			total_days = 365*year + day+1 +  18*20;
		}

		holly_year = total_days/(13*20);
		if(total_days % (13*20) == 0){holly_year--;}
		int day_left = total_days%(13*20);
		holly_day = (day_left%20 != 0) ? (day_left%20 -1): 19;
		holly_month = (day_left%13 != 0)? (day_left%13):13;
		cout<<holly_month<<" "<<holly_name[holly_day]<<" "<<holly_year<<endl;


	}




	return 0;

}