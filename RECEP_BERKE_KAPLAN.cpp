#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Takim {
	string takimAdi;
	int puan;
};

int main() {
	vector<Takim> takimlar;

	// Dosyadan okuma islemi
	ifstream okuma("giris.txt");
	if (!okuma) {
		cerr << "OKUMA HATASI" << endl;
		return 1; // Hata durumunda programi sonlandir.
	}

	string takimAdi;
	int puan;
	while (okuma >> takimAdi >> puan) {
		Takim yeniTakim;
		yeniTakim.takimAdi = takimAdi;
		yeniTakim.puan = puan;
		takimlar.push_back(yeniTakim);
	}
	okuma.close();

	// Siralama kismi
	for (int i = 0; i < takimlar.size() - 1; i++) {
		for (int j = 0; j < takimlar.size() - i - 1; j++) {
			if (takimlar[j].puan < takimlar[j + 1].puan) {
				swap(takimlar[j], takimlar[j + 1]);
			}
		}
	}
	//dosyaya ve terminale yazdirma islemi

	ofstream yazma("cikis.txt");
	if (!yazma) {
		cerr << "YAZMA HATASI" << endl;
	}
	yazma << "Sira " << " Takim  " << " Puan " << endl;
	cout << "Sira  " << " Takim  " << " Puan " << endl;
	for (int i = 0; i < takimlar.size(); i++) {
		cout << i+1 << ": " << takimlar[i].takimAdi << " " << takimlar[i].puan << endl;
		yazma << i+1 << ": " << takimlar[i].takimAdi << " " << takimlar[i].puan << endl;
	}
	yazma.close();











	return 0;
}