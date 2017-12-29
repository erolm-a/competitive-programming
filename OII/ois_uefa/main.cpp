#include<bits/stdc++.h>
using namespace std;

struct miapair {
	int coeff;
	string naz;

	bool operator>(const miapair& a) const {
		return coeff > a.coeff || (coeff == a.coeff && naz < a.naz);
	}

};
int main(){
    ifstream in("input.txt");
    int n,m;
    in >> n >> m;
    map<string,string>squadre_nazione;
    map<string,int>nazione_punti;
    string squadra,nazione;
    for (int i=0; i<n; i++){
        in >> squadra >> nazione;
        squadre_nazione[squadra] = nazione;
    }
    int punto1, punto2;
    string squadra1,squadra2;
    for(int i=0; i<m; i++){
        in >> squadra1 >> squadra2 >> punto1 >> punto2;
        nazione_punti[squadre_nazione [squadra1]] ++;
        nazione_punti[squadre_nazione[squadra2]]++;
        if(punto1 > punto2) nazione_punti[squadre_nazione[squadra1]] +=3;
        else if(punto1 == punto2) {
                nazione_punti[squadre_nazione[squadra1]] ++;
                nazione_punti[squadre_nazione[squadra2]] ++;
        }
        else nazione_punti[squadre_nazione[squadra2]] += 3;
    }
    ofstream out("output.txt");
    vector<miapair> s;
    for (auto& t : nazione_punti) s.push_back(miapair{t.second, t.first});

    sort(s.begin(), s.end(), greater<miapair>());

    for(auto& i: s)
        out << i.naz << ' ' << i.coeff << '\n';

    return 0;
}
