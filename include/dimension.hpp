struct TwoDX {
    float x;
    float y;
};

struct TwoD {
    int x;
    int y;
};

struct Dimension{
   TwoD position;
   TwoD acceleration;
   TwoD acceleration_max;
   TwoD speed;
   TwoD speed_max;
   TwoD speed_default;
   TwoD size;
   TwoD max;
};

