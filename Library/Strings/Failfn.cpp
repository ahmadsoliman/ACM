vector<int> failfn(string K) {
    vector<int> T(K.size() + 1, -1);
    for(int i = 1; i <= K.size(); i++){
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}
    return T;
}
