### Вопрос 1
1. is a
```
class Parent {
public:
int x;
protected:
int y;
private:
int z;
};

class Kid: public Parent {
public:
int func() {
    return x;
    return y;
    return z; // is inaccessible
}
};

int main() {
    Kid kid;
    kid.x;
    kid.y; // is inaccessible
    kid.z; // is inaccessible
}

```
x в Kid - public, y в Kid - protected, z недоступен для Kid
2. is implemented with