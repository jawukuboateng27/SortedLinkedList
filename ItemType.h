

enum Comparison{GREATER,LESS,EQUAL};

 class ItemType
 {
 public:
    ItemType();
    Comparison compareTo(ItemType item);
    int getValue()const;
    void initialize(int num);

 private:
    int value;
 };