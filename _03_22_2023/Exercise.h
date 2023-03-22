//
// Created by MILEN_PC on 3/22/2023.
//

#ifndef PRACTUCUMSEM2_EXERCISE_H
#define PRACTUCUMSEM2_EXERCISE_H


class Exercise {
private:
    char name[20]{};
    char description[150]{};
    int marks = 0;
public:
    explicit Exercise();
    explicit Exercise(const char* name, const char* description, int marks);
    void setName(const char* name);
    void setDescription(const char* description);
    void setMarks(int marks);
    const char* getName() const;
    const char* getDescription() const;
    int getMarks() const;
};


#endif //PRACTUCUMSEM2_EXERCISE_H
