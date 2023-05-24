//
// Created by MILEN_PC on 23.5.2023 г..
//

#ifndef PRACTUCUMSEM2_SET_H
#define PRACTUCUMSEM2_SET_H

class Set {
public:
    virtual bool contains(int ) const = 0;
    virtual ~Set() = default;
    virtual Set* clone() const = 0;
};

#endif //PRACTUCUMSEM2_SET_H
