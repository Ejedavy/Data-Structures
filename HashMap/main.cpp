#include <bits/stdc++.h>

using namespace std;

template <class R, class S>
class Node{
public:
	R key ;
	int index;
	S value;
	Node(R k, S v, int i)
	{
		key = k;
		value = v;
		index = i;
	}
	~Node(){
	}
};

template <class K, class V>
class HashMap{
private:
	hash<K> hashFunction1;
	hash<K> hashFunction2;
	Node<K,V> ** data;
	int numberofElements;
	int capacityofArray;
	Node<K,V>* dummy;
	K* defaultKey;
	V* defaultValue;
	
	
public:
	HashMap(int cap){
		capacityofArray = cap;
		data = new Node <K,V>*[cap];
		numberofElements = 0;
	}
	
	HashMap(): HashMap(1000000){
	}
	
	~HashMap(){
		delete [] data;
	}
	
	void insert(K key, V value){
		if(numberofElements == capacityofArray){
			throw invalid_argument("The map is full");
		}
		if(numberofElements == 0){
			*defaultKey = key;
			*defaultValue = value;
			dummy = new Node<K,V>(*defaultKey,*defaultValue, -1);
			Node<K,V>*placeHolder = new Node<K,V>(*defaultKey,*defaultValue,-2);
			for(int i =0 ; i < capacityofArray; i++){
				data[i] = placeHolder;
			}
		}
		int hash1 = hashFunction1(key);
		int hash2 = hashFunction2(key);
		
		int j = 0;
		int hashIndex = (hash1 + (j * hash2))%capacityofArray;
		
		while(
		data[hashIndex]->index != -2 && data[hashIndex]->index != -1 && data[hashIndex] -> key != key
		){
			j++;
			hashIndex = (hash1 + (j * hash2))%capacityofArray;
		}
		
		if( 
		data[hashIndex] -> index == -2 || data[hashIndex] -> index == -1 
		){
			Node<K,V>*temp = new Node<K,V>(key, value, hashIndex);
			data[hashIndex] = temp;
			numberofElements++;
			return;
		}
	}
	
	V get(K key){
		if(numberofElements == 0){
			throw invalid_argument("The map is empty");
		}
		int hash1 = hashFunction1(key);
		int hash2 = hashFunction2(key);
		int j = 0;
		int hashIndex = (hash1 + (j * hash2))%capacityofArray;
		int counter = 0;
		
		while(data[hashIndex] -> index != -2){
		if(counter++ > capacityofArray){
			break;
		}
		if(data[hashIndex]-> key == key){
			return data[hashIndex]-> value;
		}
			j++;
			hashIndex = (hash1 + (j * hash2))%capacityofArray;
		}
		return *(new V);
	}
	
	V remove(K key){
		if(numberofElements == 0){
			throw invalid_argument("The map is empty");
		}
		int hash1 = hashFunction1(key);
		int hash2 = hashFunction2(key);
		int j = 0;
		int hashIndex = (hash1 + (j * hash2))%capacityofArray;
		
		while(data[hashIndex] -> index != -2){
			if(data[hashIndex]-> key == key){
				V val = data[hashIndex]-> value;
				data[hashIndex] = dummy;
				numberofElements--;
				return val;
			}
			j++;
			hashIndex = (hash1 + (j * hash2))%capacityofArray;
		}return (*new V);
	}
	
};

int main(){
	HashMap<string , int> myMap;
	myMap.insert("David", 20);
	myMap.insert("Wilson", 2);
	
	cout << myMap.get("David") << endl;
	
	cout << "DONE" << endl;
	return 0;
}