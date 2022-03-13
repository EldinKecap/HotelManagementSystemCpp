#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <string>
using namespace std;
//soba klasa
class Soba{

    private:
    int brojSobe;
    int vrstaSobe;
    int stanjeSobe;

    public:
    Soba(){
    brojSobe=0;
    vrstaSobe=1;
    stanjeSobe=1;
    };
    int getBrojSobe(){return brojSobe;};
    int getVrstaSobe(){return vrstaSobe;};
    int getStanjeSobe(){return stanjeSobe;};
    void setBrojSobe(int a){brojSobe = a;};
    void setVrstaSobe(int a){vrstaSobe=a;};
    void setStanjeSobe(int a){stanjeSobe=a;};
    void display();


};
void Soba::display(){
   cout<<"Broj sobe: "<<brojSobe<<endl;
        string Ssobe;
                if(stanjeSobe == 1){
                    Ssobe = "Zauzeta";}else{
                    Ssobe = "Nije zauzeta";}

            string Vsobe;
                if(vrstaSobe == 1){
                    Vsobe = "Jednokrevetna";}else{
                    Vsobe = "Dvokrevetna";}
            cout<<"Stanje sobe: "<<Ssobe<<endl;
            cout<<"Vrsta sobe: "<<Vsobe<<endl;
}
//klasa radnik
class Radnik{
    private:
        string ime;
        string prezime;
        string zanimanje;
        long long JMBG;
        int plata;

    public:
        string getIme(){return ime;};
        string getPrezime(){return prezime;};
        string getZanimanje(){return zanimanje;};
        long long getJMBG(){return JMBG;};
        int getPlata(){return plata;};

        void setIme(string a ){ ime = a ;};
        void setPrezime(string a){prezime=a;};
        void setZanimanje (string a){zanimanje=a;};
        void setJMBG (long long a){JMBG=a;};
        void setPlata (int a){plata=a;};
        void display();

};

void Radnik::display(){
    cout<<"Ime Radnika: "<<ime<<endl;
    cout<<"Prezime Radnika: "<<prezime<<endl;
    cout<<"Zanimanje Radnika: "<<zanimanje<<endl;
    cout<<"JMBG Radnika: "<<JMBG<<endl;
    cout<<"Plata Radnika: "<<plata<<endl;
}
//Gost klasa
class Gost{
private:
        string ime;
        string prezime;
        string brojTelefona;
        int brojSobe;
        int dodatneUsluge;
        int rezervacije;
    public:
        string getIme(){return ime;};
        string getPrezime(){return prezime;};
        string getBrojTelefona(){return brojTelefona;};
        int getBrojSobe(){return brojSobe;};
        int getDodatneUsluge(){return dodatneUsluge;};
        int getRezervacije(){return rezervacije;};

        void setIme(string a ){ ime = a ;};
        void setPrezime(string a){prezime=a;};
        void setBrojTelefona (string a){brojTelefona=a;};
        void setBrojSobe(int a){brojSobe = a;};
        void setDodatneUsluge(int a){dodatneUsluge = a;};
        void setRezervacije(int a){rezervacije = a;};
        void display();
};
void Gost::display(){
    cout<<"Ime Radnika: "<<ime<<endl;
    cout<<"Prezime Radnika: "<<prezime<<endl;
   cout<<"Broj Telefona: "<<brojTelefona<<endl;
   cout<<"Broj Sobe: "<<brojSobe<<endl;
        string dodUsluge;
                if(dodatneUsluge == 1){
                    dodUsluge = "Teretana";}else if(dodatneUsluge==2){
                    dodUsluge = "Bazen";}else{
                    dodUsluge = "Nema dodatne usluge";
                    }
            cout<<"Dodatne usluge: "<<dodUsluge<<endl;
            string rezer;
                if(rezervacije == 1){
                    rezer = "Ima rezervaciju";}else{
                    rezer = "Nema rezervaciju";}
            cout<<"Rezervacija : "<<rezer<<endl;

}
#endif // CLASSES_H_INCLUDED
