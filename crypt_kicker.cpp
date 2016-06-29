#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;

bool Find(vector<set<string>> &dict,vector<string> &line, map<char,char> &dec,int localized)
{
    //Verifica se não chegou no fim da linha
    if(localized<line.size())
    {
        //Pega o tamanho da palavra atual
        int strLen=line[localized].size();
        string test;
        test.resize(strLen,'A');
        //Tenta decodificar a palavra atual
        for(int i=0; i<strLen; i++)
        {
            if(dec.find(line[localized][i])!=dec.end())
                test[i]=dec[line[localized][i]];
        }
        //Verifica em todas as palavras do dicionário se alguma tem o tamanho da palavra atual
        for(set<string>::iterator it=dict[strLen].begin(); it!=dict[strLen].end(); it++)
        {
            bool notMatch=false;
            for(int i=0; i<strLen; i++)/*Usa o 'A' para verificar se é um caractere não decodificado, se for um caractere
                              não decodificado e ele não corresponder a um caracter na palavra, então não deu match!*/
                if(test[i]!='A'&&test[i]!=(*it)[i])
                    notMatch=true;
            if(notMatch)
                continue;
            for(int i=0; i<strLen; i++)
                //se é um match possivel, então coloca o cara identificado pra fazer a decodificação
                if(test[i]=='A')
                    dec.insert(pair<char,char> (line[localized][i],(*it)[i]));
            //Continua decodificando
            if(Find(dict,line,dec,localized+1))
                return true;
            //Se deu falha então remove os caracteres que foram adicionados
            for(int i=0; i<strLen; i++)
                if(test[i]=='A')
                    dec.erase(line[localized][i]);
        }
        if(localized==0)
        {
            //Se chegamos aqui então, nada foi encontrado... preenche o mapa<decod> com asteriscos
            string b="qwertyuiopasdfghjklzxcvbnm";
            for(int i=0; i<b.size(); i++)
                dec.insert(pair<char,char> (b[i],'*'));
        }
        return false;
    }
    return true;
}
int main()
{
    int size;
    cin >> size;
    vector<set<string>> dict;
    dict.resize(17);
    string choose;
    for(int i=0; i<size; i++)
    {
        //preenchendo o dicionário
        cin >> choose;
        dict[choose.size()].insert(choose);
    }
    while(getline(cin,choose))
    {
        stringstream in(stringstream::in |stringstream::out);
        in << choose;
        vector<string> line;
        while(in >> choose)
            line.push_back(choose);
        map<char,char> dec;
        Find(dict,line,dec,0);
        for(int i=0; i<line.size(); i++)
        {
            for(int j=0; j<line[i].size(); j++)
                cout << dec[line[i][j]];
            if(i!=line.size()-1)
                cout << " ";
            else
                cout << endl;
        }
    }
}
