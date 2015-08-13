#include <bits/stdc++.h>
using namespace std;

int main(){
	string query;
	cin >> query;

	if(query.size() == 1){
		cout << query[0] - 'a' + 1 << "\n";
		return 0;
	}

	int conteo = 26;
	for(int a = 1; a <= 26; a++){
		for(int b = a + 1; b <= 26; b++){
			conteo++;
			if(query.size() == 2){
				if(query[0] == char(a + 'a' - 1) && query[1] == char(b + 'a' - 1)){
					cout << conteo << "\n";
					return 0;
				}
			}
		}
	}

	for(int a = 1; a <= 26; a++){
		for(int b = a + 1; b <= 26; b++){
			for(int c = b + 1; c <= 26; c++){
				conteo++;
				if(query.size() == 3){
					if(query[0] == char(a + 'a' - 1) && query[1] == char(b + 'a' - 1) && query[2] == char(c + 'a' - 1)){
						cout << conteo << "\n";
						return 0;
					}
				}
			}
		}
	}

	for(int a = 1; a <= 26; a++){
		for(int b = a + 1; b <= 26; b++){
			for(int c = b + 1; c <= 26; c++){
				for(int d = c + 1; d <= 26; d++){
					conteo++;
					if(query.size() == 4){
						if(query[0] == char(a + 'a' - 1) && 
							query[1] == char(b + 'a' - 1) && 
							 query[2] == char(c + 'a' - 1) && 
							  query[3] == char(d + 'a' - 1)){
							cout << conteo << "\n";
							return 0;
						}
					}
				}
			}
		}
	}

	for(int a = 1; a <= 26; a++){
		for(int b = a + 1; b <= 26; b++){
			for(int c = b + 1; c <= 26; c++){
				for(int d = c + 1; d <= 26; d++){
					for(int e = d + 1; e <= 26; e++){
						conteo++;
						if(query.size() == 5){
							if(query[0] == char(a + 'a' - 1) && 
								query[1] == char(b + 'a' - 1) && 
								 query[2] == char(c + 'a' - 1) && 
								  query[3] == char(d + 'a' - 1) &&
								   query[4] == char(e + 'a' - 1)){
								cout << conteo << "\n";
								return 0;
							}
						}
					}
				}
			}
		}
	}

	for(int a = 1; a <= 26; a++){
		for(int b = a + 1; b <= 26; b++){
			for(int c = b + 1; c <= 26; c++){
				for(int d = c + 1; d <= 26; d++){
					for(int e = d + 1; e <= 26; e++){
						for(int f = e + 1; f <= 26; f++){
							conteo++;
							if(query.size() == 6){
								if(query[0] == char(a + 'a' - 1) && 
									query[1] == char(b + 'a' - 1) && 
									 query[2] == char(c + 'a' - 1) && 
									  query[3] == char(d + 'a' - 1) &&
									   query[4] == char(e + 'a' - 1) &&
									    query[5] == char(f + 'a' - 1)){
									cout << conteo << "\n";
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}

	cout << 0 << "\n";
	return 0;
}
