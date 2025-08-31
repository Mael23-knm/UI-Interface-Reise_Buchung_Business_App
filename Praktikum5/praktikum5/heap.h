/* 
 * File:   heap.h
 * Author: arnim
 *
 * Created on 13. Dezember 2013, 07:51
 */

#ifndef HEAP_H
#define	HEAP_H
#include <stdexcept>
#include <string>

struct VertexData {
    int vertexNumber;
    std::string vertexName;
    int endTime;
};

class Heap {
public:
    // Erstelle einen Heap aus dem Array a[] mit size Elementen
    Heap(VertexData a[], unsigned int size);
    ~Heap();
    VertexData pop();
    
private:
    void heapify(unsigned int start);
    VertexData* data;
    unsigned int pointer;
};
#endif	/* HEAP_H */

