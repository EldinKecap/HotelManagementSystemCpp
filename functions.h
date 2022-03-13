
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>
#include "Classes.h"
using namespace std;
//uzima sa tastature i provjerava unos da li je string ili veci od limita

template <typename T>
T provjeraUnosa(T &unos,T limit){
    while (!(cin>>unos)){
        cout <<"Unesite broj:"<<endl;
        cin.clear();
        cin.ignore(100,'\n');
    }
    while(unos>limit){
        cout<<"Broj koji ste unijeli nije jedna od ponudjenih opcija.Unesite novi broj:"<<endl;
        cin>>unos;
    }
    return unos;
}
//provjerava string
void ProvjeraStringa(string &input)
{
     cin>>input;
     if(input.size()>2){
	for (int i = 0; i < input.size(); i++)
	{
		int uppercaseChar = toupper(input[i]); //Convert character to upper case version of character
		if (uppercaseChar < 'A' || uppercaseChar > 'Z') //If character is not A-Z
		{
		    cout<<"Greska.Unijeli ste broj.Pokusajte ponovo"<<endl;
			ProvjeraStringa(input);
		}
	}}else{
	cout<<"Greska unijeli ste manje od 3 slova"<<endl;
	ProvjeraStringa(input);
	}
	//At this point, we have gone through every character and checked it.

}
//provjera broja telefona
void provjeraTelefona(string &input)
{
     cin>>input;
     if(input.size()>9){
	for (int i = 0; i < input.size(); i++)
	{
		int uppercaseChar = toupper(input[i]); //Convert character to upper case version of character
		if (!(uppercaseChar < 'A' || uppercaseChar > 'Z')) //If character is not A-Z
		{
		    cout<<"Greska.Unijeli ste slovo.Pokusajte ponovo"<<endl;
			provjeraTelefona(input);
		}
	}
	}else{
	cout<<"Greska unijeli ste manje od 9 cifara"<<endl;
	provjeraTelefona(input);
	}
	//At this point, we have gone through every character and checked it.
	 //Return true since every character had to be A-Z
}
//provjera jmbg
long long provjeraUnosaJMBG(long long &unos){
    while (!(cin>>unos)){
        cout <<"Unesite broj:"<<endl;
        cin.clear();
        cin.ignore(100,'\n');
    }
    while(unos<1000000000000||unos>9999999999999){
        cout<<"Broj koji ste unijeli nije jedna od ponudjenih opcija.Unesite novi broj:"<<endl;
        cin>>unos;
    }
    return unos;
}
//ispisuje vektor
template <class B>
void printVector ( const vector<B>& vect){
     int redniBroj = 1 ;
     for(B vecto : vect ){
            cout<<"----------------------------------"<<endl;
            cout<<"Redni broj : "<<redniBroj <<endl ;
            vecto.display();
            redniBroj++;

        }
}
//brise clan vektora
template <class C>
void deleteVectorMember (vector <C>& Vect , int brojClanaZaBrisanje){
    Vect.erase(Vect.begin()+brojClanaZaBrisanje-1);
}
// MENU
int mainMenu(){
    cout<<"-------------------------------------------"<<endl;
    cout<<"Unesite broj da izaberete opciju:"<<endl;
    cout<<"1.Sobe"<<endl;
    cout<<"2.Radnici"<<endl;
    cout<<"3.Gosti"<<endl;
    cout<<"4.Dodatne usluge"<<endl;
    cout<<"5.Rezervacije"<<endl;
    cout<<"6.Ugasi program"<<endl;
    int a;


    a=provjeraUnosa(a,6);
    return a;
}
//soba meni
int sobaMenu(){
        cout<<"----------------------------------"<<endl;
        cout<<"1.Unesite novu sobu"<<endl;
        cout<<"2.Izbrisite sobu"<<endl;
        cout<<"3.Uredite podatke postojece sobe"<<endl;
        cout<<"4.Pronadite podatke o postojecoj sobi"<<endl;
        cout<<"5.Povratak na glavni meni"<<endl;
        int a;

        a=provjeraUnosa(a,5);
        return a;
}
//radnik meni
int radnikMenu(){
        cout<<"----------------------------------"<<endl;
        cout<<"1.Unesite novog radnika"<<endl;
        cout<<"2.Izbrisite radnika"<<endl;
        cout<<"3.Uredite podatke postojeceg radnika:"<<endl;
        cout<<"4.Pronadite podatke o postojecem radniku"<<endl;
        cout<<"5.Povratak na glavni meni"<<endl;
        int a;

        a=provjeraUnosa(a,5);
}
//gost meni
int gostMenu(){
        cout<<"----------------------------------"<<endl;
        cout<<"1.Unesite novog gosta"<<endl;
        cout<<"2.Izbrisite gosta"<<endl;
        cout<<"3.Uredite podatke postojecem gostu:"<<endl;
        cout<<"4.Pronadite podatke o postojecem gostu"<<endl;
        cout<<"5.Povratak na glavni meni"<<endl;
        int a;

        a=provjeraUnosa(a,5);
}
//klase vektori definicije
class Soba soba1;
vector <Soba> sobe;
class Radnik radnik1;
vector <Radnik> radnici;
class Gost gost1;
vector <Gost> gosti;

//sub menu
void subMenu(){
    int izbor = mainMenu();
    system("cls");

    if (izbor == 1){
        //Soba
        int a;
        a = sobaMenu();
        system("cls");
        //1. Unesite novu sobu
        if(a==1){
        cout<<"Unesite broj sobe (maksimalni broj je 100)"<<endl;
        int brojSobe;
        brojSobe=provjeraUnosa(brojSobe,100);
        soba1.setBrojSobe(brojSobe);
        cout<<"Da li je soba:"<<endl;
        cout<<"1.Jednokrevetna"<<endl;
        cout<<"2.Dvokrevetna"<<endl;
        int b;
        b=provjeraUnosa(b,2);
        soba1.setVrstaSobe(b);
        string Vsobe;
        if(soba1.getVrstaSobe()==1){
                Vsobe = "Jednokrevetna";}else{
                   Vsobe = "Dvokrevetna";}
        cout<<"Da li je soba zauzeta?"<<endl;
        cout<<"1.Da"<<endl;
        cout<<"2.Ne"<<endl;
        int c;
        c=provjeraUnosa(c,2);
        soba1.setStanjeSobe(c);
        string Ssobe;
        if(soba1.getStanjeSobe()==1){
                Ssobe = "Zauzeta";}else{
                   Ssobe = "Nije zauzeta";}
        cout<<"Broj sobe je:" << soba1.getBrojSobe() <<endl;
        cout<<"Vrsta sobe je:" << Vsobe <<endl;
        cout<<"Stanje sobe je:" << Ssobe <<endl;
        cout<<"Da sacuvate sobu unesite nulu ili bilo sta drugo za povratak na meni Sobe."<<endl;
        int save;
        cin>>save;

        if(save==0){
            sobe.push_back(soba1);
            cout<<"Uspjesno ste sacuvali sobu : "<<endl;
            printVector(sobe);
            subMenu();
        }else{
         subMenu();
        }
        }
        //2.Izbrisite sobu
        if(a==2){

         if(sobe.empty()){
            cout<<"Nema unesenih soba"<<endl;
            subMenu();
         }else{
            int brojSoba = sobe.size() ;
        //Ispisuje listu soba
            printVector(sobe);
            cout<<"Unesite redni broj sobe koju zelite izbrisati" <<endl;
            int brojSobeZaBrisanje;
            brojSobeZaBrisanje= provjeraUnosa(brojSobeZaBrisanje,brojSoba);
            //brise sobu
            deleteVectorMember(sobe,brojSobeZaBrisanje);
            cout<<"Soba je izbrisana"<<endl;
       if(sobe.empty()){
            cout<<"Nema unesenih soba"<<endl;
         }else{
             cout<<"Preostale sobe"<<endl;
         printVector(sobe);
         }
         subMenu();
         }

        }
        if(a==3){
            if(!sobe.empty()){
            printVector(sobe);
            cout<<"Unesite redni broj sobe cije podatke zelite da uredite"<<endl;
            int brojClanaKojiMjenjamo;
            int velicinaVektora = sobe.size();
            brojClanaKojiMjenjamo = provjeraUnosa(brojClanaKojiMjenjamo,velicinaVektora);
            cout<<"Unesite novi broj sobe (maksimalni broj je 100)"<<endl;
            int brojSobe;
            brojSobe=provjeraUnosa(brojSobe,100);
            sobe[brojClanaKojiMjenjamo-1].setBrojSobe(brojSobe);
            cout<<"Da li je nova soba:"<<endl;
            cout<<"1.Jednokrevetna"<<endl;
            cout<<"2.Dvokrevetna"<<endl;
            int b;
            b=provjeraUnosa(b,2);
            sobe[brojClanaKojiMjenjamo-1].setVrstaSobe(b);
            cout<<"Da li je nova soba zauzeta?"<<endl;
            cout<<"1.Da"<<endl;
            cout<<"2.Ne"<<endl;
            int c;
            c=provjeraUnosa(c,2);
            sobe[brojClanaKojiMjenjamo-1].setStanjeSobe(c);
            cout<<"Uspjesno ste izmjenili sobu";
            printVector(sobe);
            subMenu();
            }else{
            cout<<"Nema unesenih soba "<<endl;
            subMenu();
}
        }
        if(a==4){
                if(sobe.empty()){
                    cout<<"Nema unesenih soba"<<endl;
                    subMenu();
                }else{
                    printVector(sobe);
                    subMenu();
                    }
        }
        if (a==5){
            subMenu();
        }
        }
    if(izbor==2){
          //radnik
        int a;
        a = radnikMenu();
        system("cls");
        if(a==1){
            cout<<"Unesite ime radnika"<<endl;
            string IME;
            ProvjeraStringa(IME);
            radnik1.setIme(IME);
            cout<<"Unesite prezime radnika"<<endl;
            string prezime;
            ProvjeraStringa(prezime);
            radnik1.setPrezime(prezime);
            cout<<"Unesite zanimanje radnika"<<endl;
            string zanimanje;
            ProvjeraStringa(zanimanje);
            radnik1.setZanimanje(zanimanje);
            cout<<"Unesite JMBG radnika"<<endl;
            long long jmbg;
            jmbg=provjeraUnosaJMBG(jmbg);
            radnik1.setJMBG(jmbg);
            cout<<"Unesite platu radnika"<<endl;
            int plata;
            cin>>plata;
            radnik1.setPlata(plata);
            radnici.push_back(radnik1);

            printVector(radnici);
            subMenu();

        }
        if(a==2){

             if(radnici.empty()){
            cout<<"Nema unesenih radnika"<<endl;
            subMenu();
         }else{
            int brojSoba = radnici.size() ;
        //Ispisuje listu radnika
            printVector(radnici);
            cout<<"Unesite redni broj radnika kojeg zelite izbrisati" <<endl;
            int brojSobeZaBrisanje;
            brojSobeZaBrisanje= provjeraUnosa(brojSobeZaBrisanje,brojSoba);
            //brise sobu
            deleteVectorMember(radnici,brojSobeZaBrisanje);
            cout<<"Radnik je izbrisan"<<endl;
       if(radnici.empty()){
            cout<<"Nema unesenih radnika"<<endl;
         }else{
             cout<<"Preostali radnici"<<endl;
         printVector(radnici);
         }
         subMenu();
         }
        }
        if(a==3){
            if(radnici.empty()){
                cout<<"Nema unesenih radnika"<<endl;
                subMenu();
            }else{
            printVector(radnici);
            cout<<"Unesite redni broj radnika cije podatke zelite da uredite"<<endl;
            int brojClanaKojiMjenjamo;
            int velicinaVektora = radnici.size();
            brojClanaKojiMjenjamo = provjeraUnosa(brojClanaKojiMjenjamo,velicinaVektora);
            cout<<"Unesite novo ime radnika"<<endl;
            string IME;
            ProvjeraStringa(IME);
            radnici[brojClanaKojiMjenjamo-1].setIme(IME);
            cout<<"Unesite novo prezime radnika"<<endl;
            string prezime;
            ProvjeraStringa(prezime);
            radnici[brojClanaKojiMjenjamo-1].setPrezime(prezime);
            cout<<"Unesite novo zanimanje radnika"<<endl;
            string zanimanje;
            ProvjeraStringa(zanimanje);
            radnici[brojClanaKojiMjenjamo-1].setZanimanje(zanimanje);
            cout<<"Unesite novi JMBG radnika"<<endl;
            long long jmbg;
            jmbg=provjeraUnosaJMBG(jmbg);
            radnici[brojClanaKojiMjenjamo-1].setJMBG(jmbg);
            cout<<"Unesite novu platu radnika"<<endl;
            int plata;
            cin>>plata;
            radnici[brojClanaKojiMjenjamo-1].setPlata(plata);


            printVector(radnici);
            subMenu();
            }
        }
        if(a==4){
         if(radnici.empty()){
                    cout<<"Nema unesenih radnika"<<endl;
                    subMenu();
                }else{
                    printVector(radnici);
                    subMenu();
                    }
        }
        if(a==5){
            subMenu();
        }

        }
    if (izbor == 3){
        //Gost
        int a;
        a = gostMenu();
        system("cls");
            if(a==1){
                //unos gosta
            cout<<"Unesite ime gosta"<<endl;
            string IME;
            ProvjeraStringa(IME);
            gost1.setIme(IME);
            cout<<"Unesite prezime gosta"<<endl;
            string prezime;
            ProvjeraStringa(prezime);
            gost1.setPrezime(prezime);
            cout<<"Unesite broj telefona gosta"<<endl;
            string broj;
            provjeraTelefona(broj);
            gost1.setBrojTelefona(broj);
            cout<<"Unesite broj sobe gosta (maksimalni broj je 100)"<<endl;
            int brojSobe;
            brojSobe=provjeraUnosa(brojSobe,100);
            gost1.setBrojSobe(brojSobe);

            cout<<"Da li gost ima dodatne usluge:"<<endl;
        cout<<"1.Teretana"<<endl;
        cout<<"2.Bazen"<<endl;
        cout<<"3.Nema dodatne usluge"<<endl;
        int b;
        b=provjeraUnosa(b,3);
        gost1.setDodatneUsluge(b);

        cout<<"Da li gost ima rezervacije"<<endl;
        cout<<"1.Da"<<endl;
        cout<<"2.Ne"<<endl;
        int c;
        c=provjeraUnosa(c,2);
        gost1.setRezervacije(c);
        gosti.push_back(gost1);
        printVector(gosti);
        subMenu();
        }
        if(a==2){
           if(gosti.empty()){
            cout<<"Nema unesenih gostiju"<<endl;
            subMenu();
         }else{
            int brojSoba = gosti.size() ;
        //Ispisuje listu radnika
            printVector(gosti);
            cout<<"Unesite redni broj gosta kojeg zelite izbrisati" <<endl;
            int brojSobeZaBrisanje;
            brojSobeZaBrisanje= provjeraUnosa(brojSobeZaBrisanje,brojSoba);
            //brise gosta
            deleteVectorMember(gosti,brojSobeZaBrisanje);
            cout<<"Gost je izbrisan"<<endl;
       if(gosti.empty()){
            cout<<"Nema unesenih gostiju"<<endl;
         }else{
             cout<<"Preostali gosti"<<endl;
         printVector(gosti);
         }
         subMenu();
         }
        }
        if(a==3){
            if(gosti.empty()){
                cout<<"Nema unesenih gostiju"<<endl;
                subMenu();
            }else{
            printVector(gosti);
            cout<<"Unesite redni broj gosta cije podatke zelite da uredite"<<endl;
            int brojClanaKojiMjenjamo;
            int velicinaVektora = gosti.size();
            brojClanaKojiMjenjamo = provjeraUnosa(brojClanaKojiMjenjamo,velicinaVektora);
             cout<<"Unesite novo ime gosta"<<endl;
            string IME;
            ProvjeraStringa(IME);
            gosti[brojClanaKojiMjenjamo-1].setIme(IME);
            cout<<"Unesite novo prezime gosta"<<endl;
            string prezime;
            ProvjeraStringa(prezime);
            gosti[brojClanaKojiMjenjamo-1].setPrezime(prezime);
            cout<<"Unesite novi broj telefona gosta"<<endl;
            string broj;
            provjeraTelefona(broj);
            gosti[brojClanaKojiMjenjamo-1].setBrojTelefona(broj);
            cout<<"Unesite novi broj sobe gosta (maksimalni broj je 100)"<<endl;
            int brojSobe;
            brojSobe=provjeraUnosa(brojSobe,100);
            gosti[brojClanaKojiMjenjamo-1].setBrojSobe(brojSobe);

            cout<<"Da li gost ima dodatne usluge:"<<endl;
        cout<<"1.Teretana"<<endl;
        cout<<"2.Bazen"<<endl;
        cout<<"3.Nema dodatne usluge"<<endl;
        int b;
        b=provjeraUnosa(b,3);
        gosti[brojClanaKojiMjenjamo-1].setDodatneUsluge(b);

        cout<<"Da li gost ima rezervacije"<<endl;
        cout<<"1.Da"<<endl;
        cout<<"2.Ne"<<endl;
        int c;
        c=provjeraUnosa(c,2);
        gosti[brojClanaKojiMjenjamo-1].setRezervacije(c);
        printVector(gosti);
            subMenu();
        }
    }
    if(a==4){
        if(gosti.empty()){
                    cout<<"Nema unesenih gostiju"<<endl;
                    subMenu();
                }else{
                    printVector(gosti);
                    subMenu();
                    }
    }
    if(a==5){
        subMenu();
    }
}
   if(izbor==4){
        if(gosti.empty()){
                    cout<<"Nema unesenih gostiju"<<endl;
                    subMenu();
                }else{

        int redniBroj = 1 ;
     for(Gost gost : gosti ){
            cout<<"----------------------------------"<<endl;
            cout<<"Redni broj : "<<redniBroj <<endl ;
            cout<<"Ime gosta:"<<gost.getIme()<<endl;
            string dodUsluge;
                if(gost.getDodatneUsluge() == 1){
                    dodUsluge = "Teretana";}else if(gost.getDodatneUsluge() == 2){
                    dodUsluge = "Bazen";}else{
                    dodUsluge = "Nema dodatne usluge";
                    }
            cout<<"Dodatne usluge: "<<dodUsluge<<endl;
            redniBroj++;

        }
    subMenu();
                }
   }
   if(izbor==5){
         if(gosti.empty()){
                    cout<<"Nema unesenih gostiju"<<endl;
                    subMenu();
                }else{
     int redniBroj = 1 ;
     for(Gost gost : gosti ){
            cout<<"----------------------------------"<<endl;
            cout<<"Redni broj : "<<redniBroj <<endl ;
            cout<<"Ime gosta:"<<gost.getIme()<<endl;
            string rezer;
                if(gost.getRezervacije() == 1){
                    rezer = "Ima rezervaciju";}else{
                    rezer = "Nema rezervaciju";}
            cout<<"Rezervacija : "<<rezer<<endl;
            redniBroj++;

        }
    subMenu();
                }
   }
    if(izbor==6){
        exit(0);
    }

}
#endif // FUNCTIONS_H_INCLUDED
