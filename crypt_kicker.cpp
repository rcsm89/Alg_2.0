#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;

bool Find(vector<set<string>> &dict,vector<string> &line, map<char,char> &dec,int spot){
  //Check that the end of the line hasn't been reached
  if(spot<line.size()){
    //Get the size of the current word
    int sSize=line[spot].size();
    string cand;
    cand.resize(sSize,'A');
    //Attempt to decode the current word
    for(int i=0;i<sSize;i++){
      if(dec.find(line[spot][i])!=dec.end())
         cand[i]=dec[line[spot][i]];
    }   
    //Check all strings in the dictionary of the current length                
    for(set<string>::iterator it=dict[sSize].begin();it!=dict[sSize].end();it++){
      bool notMatch=false;
      for(int i=0;i<sSize;i++)
       //A is used to signify an undecoded character, this if says if the character was
       // decoded and it does not equal to corresponding character in the word, it's not a match
       if(cand[i]!='A'&&cand[i]!=(*it)[i])
        notMatch=true;
     if(notMatch)
       continue;
      for(int i=0;i<sSize;i++)
      //if it is a feasible match, then add the learned characters to the decoder
    if(cand[i]=='A')
      dec.insert(pair<char,char> (line[spot][i],(*it)[i]));
      //Keep decoding
      if(Find(dict,line,dec,spot+1))
    return true;
      //If decoding failed, then remove added characters
      for(int i=0;i<sSize;i++)
    if(cand[i]=='A')
      dec.erase(line[spot][i]);
    }
    if(spot==0){
      //This means no solution was found, fill decoder with a map to astericks
      string b="qwertyuiopasdfghjklzxcvbnm";
      for(int i=0;i<b.size();i++)
    dec.insert(pair<char,char> (b[i],'*'));
    }
    return false;
  }
  return true;
}
int main(){
  int size;
  cin >> size;
  vector<set<string>> dict;
  dict.resize(17);
  string grab;
  for(int i=0;i<size;i++){
    //Bucket dictionary
    cin >> grab;
    dict[grab.size()].insert(grab);
  }
  while(getline(cin,grab)){
    stringstream in(stringstream::in |stringstream::out);
    in << grab;
    vector<string> line;
    while(in >> grab)
      line.push_back(grab);
    map<char,char> dec;
    Find(dict,line,dec,0);
    for(int i=0;i<line.size();i++){
      for(int j=0;j<line[i].size();j++)
    cout << dec[line[i][j]];
      if(i!=line.size()-1)
    cout << " ";
      else
    cout << endl;
    }
  }
}
