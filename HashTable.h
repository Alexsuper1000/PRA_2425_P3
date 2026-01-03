#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"
#include "../P1/ListLinked.h" 

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
        int max; 
       
        ListLinked<TableEntry<V>>* table; 

        int h(std::string key) {
            int sum = 0;
            for (char c : key) {
                sum += int(c);
            }
            return sum % max;
        }

    public:
        HashTable(int size) {
            max = size;
            n = 0;
            table = new ListLinked<TableEntry<V>>[max]; 
        }

        ~HashTable() {
            delete[] table; 
        }

        int capacity() {
            return max;
        }

        void insert(std::string key, V value) override {
            int pos = h(key);
            TableEntry<V> entry(key, value);
           
            if (table[pos].search(entry) != -1) {
                throw std::runtime_error("Key '" + key + "' already exists!");
            }

            table[pos].prepend(entry);
            n++;
        }

        V search(std::string key) override {
            int pos = h(key);
            TableEntry<V> entry(key);
            
            int index = table[pos].search(entry);
            if (index == -1) {
                throw std::runtime_error("Key '" + key + "' not found!");
            }
            
            return table[pos].get(index).value;
        }

        V remove(std::string key) override {
            int pos = h(key);
            TableEntry<V> entry(key);
            
            int index = table[pos].search(entry);
            if (index == -1) {
                throw std::runtime_error("Key '" + key + "' not found!");
            }
            
            TableEntry<V> deleted = table[pos].remove(index);
            n--;
            return deleted.value;
        }

        int entries() override {
            return n;
        }

        V operator[](std::string key) {
            return search(key);
        }

        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << std::endl;
            out << "==============" << std::endl << std::endl;
            for (int i = 0; i < th.max; i++) {
                out << "== Cubeta " << i << " ==" << std::endl << std::endl;
                out << th.table[i] << std::endl;
                out << std::endl;
            }
            out << "==============" << std::endl;
            return out;
        }
};

#endif 
