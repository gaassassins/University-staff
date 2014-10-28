vector<int> compute_prefix_function(const string& s) {
	int len = s.length();
	vector<int> p(len); // значения префикс-функции
	                  // индекс вектора соответствует номеру последнего символа аргумента
	p[0] = 0; // для префикса из нуля и одного символа функция равна нулю
 
        int k = 0;
	for(int i = 1; i < len; i++) {		
		while ( (k > 0) && (s[k] != s[i]) ) 
			k = p[k-1]; 
		if (s[k] == s[i])
			k++;
		p[i] = k;
	}
	return p;
}