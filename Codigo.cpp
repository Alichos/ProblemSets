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
