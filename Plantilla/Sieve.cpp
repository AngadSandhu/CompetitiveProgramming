vector<int> prime;
bool notprime[N];
int mobius[N];
void sieve() {
	memset(notprime,0,sizeof notprime);
    mobius[1] = 1;
	for(int i = 2; i < N ; i++){
		if(!notprime[i]) {
			prime.push_back(i);
            mobius[i] = -1;
		}
		for(int j = 0; j < prime.size () && i * prime[j] < N ; ++j){
			notprime[i*prime[j]] = true;
			if(i % prime[j] == 0){
                mobius[i*prime[j]] = 0;
				break;
			}else {
                mobius[i*prime[j]] = mobius[i]*mobius[prime[j]];
			}
		}
	}
}