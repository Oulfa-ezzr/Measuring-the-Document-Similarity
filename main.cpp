//inclure les bibliothèques
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <cmath>

using namespace std;

//les fonctions  utilisé
void constF_v(string lien,vector< vector <string> > &fog,int &cpt);
double produitS(vector< vector <string> > v1,vector< vector <string> > v2,int cpt1,int cpt2);



int main() 
{
//les variables utilisé

string lien;
vector< vector <string> > v1,v2;
double prodS,result;
int cpt1,cpt2;

//lire fichier 1 & construction du vecteur

 lien="totoo.txt";
 constF_v(lien,v1,cpt1);     

//lire fichier 2& construction du vecteur

 lien="toto.txt";
 constF_v(lien,v2,cpt2); 
//produit scalaire

prodS=produitS(v1,v2,cpt1,cpt2);
//cos

result = acos(prodS);

//resultat obtenu en Degree (*180/3.1415 )

  cout << "La différence entre ces 2 fichiers est " << result*180/3.1415  <<" \% "<<endl ;
    return 0;
}






void constF_v(string lien,vector< vector <string> > &fog,int &cpt)
{
     int i,j,freq,l;
     string mot,motR;
     bool exst;
     //lire fichier
      ifstream f (lien);
    if (!f.is_open())
    {
         cout << "Impossible d'ouvrir le fichier en lecture !" << endl;
    }
    else
    {
        //construction du vecteur
       cpt=0;//pour compter le nombre des mots
     while(!f.eof())
     {
         vector <string> fogRow;
         exst=false; 
         j=0;
         i=f.tellg();
         if (i==-1) break ;
         f >> mot;
         fogRow.push_back( mot ); //ajouter le mot dans le vecteur
         l=mot.size();
         f.seekg(j);
          //cherche si le mot est déja exsité dans le vecteur
         while((j<i) & (exst==false)) 
         {     
            f >>motR;
            j=j+motR.size()+1;
            if(motR==mot)
              exst=true;
         }
         //si le mot n'exsite pas on recherche ces occurences 
         if(exst==false)
         {
              freq=1;
              j=i+l+1;
              f.seekg(j);
           while(!f.eof())
             {   
                 f >>motR;
                 if(motR==mot)
                   freq +=1;
             }
          cpt += freq;
          //ajouter le nombre d'occurence dans le vecteur
          fogRow.push_back( to_string(freq) );
          fog.push_back(fogRow);
         }
         f.seekg(i+l+1)  ;
         
      }
     f.close(); 
    }
}  
double produitS(vector< vector <string> > v1,vector< vector <string> > v2,int cpt1,int cpt2)
{  
   bool exst;
   int som=0,s,i,j;
   double res;
    //cherche si le mot exite dans les 2 vecteurs
   for(i=0;i<v1.size();i++)
   {
     exst=false; j=0;
     while ((exst==false) & (j<v2.size()))
     { 
       if(v1[i][0]==v2[j][0])
       {
         s= stoi(v1[i][1])*stoi(v2[j][1]);
         som +=s;
         exst=true;
       }
       else j+=1;
     }
   }
   res =(double)som/(cpt1*cpt2);
  return res;

}
