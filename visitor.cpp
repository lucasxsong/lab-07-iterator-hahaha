#include "visitor.h"
#include "composite.h"

#include <string>

PrintVisitor::PrintVisitor() {}

void PrintVisitor::rootNode() {
    return; 
}

void PrintVisitor::sqrNode() {
    output =+ " ^ ";
}

void PrintVisitor::multNode() {
    output += " * ";
}

void PrintVisitor::subNode() {
    output += " - ";
}

void PrintVisitor::addNode() {
    output += " + ";
}

void PrintVisitor::opNode(Op* op) {
    double x = op->evaluate();
    output += " ";
    output += to_string(x);
    output += " ";
}

void PrintVisitor::execute() {
    cout << output << endl;
}