#ifndef __RECTANGULAR_HPP__
#define __RECTANGULAR_HPP__
    class rectangular{
        private:
            float x_maks, x_min, y_maks, y_min;
        public:
            rectangular(float midpoint_x, float midpoint_y, float length, float width);
            bool operator== (rectangular const &)const;
            rectangular operator+ (rectangular const &);
            rectangular operator- (rectangular const &);
            void operator++ ();
            void operator++(int);
            void operator-- ();
            void operator--(int);
            float operator[](int pilihan);
            void output();
    };
#endif