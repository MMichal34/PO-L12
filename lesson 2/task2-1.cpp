#include <iostream>

using namespace std;

class Tissue_box{
    int tissues;
    string brand_name;
    int box_id;
    float price;
public:
    Tissue_box():tissues(0),brand_name("Chustpol"),box_id(0),price(0.0){};
    Tissue_box(int tis,string bra):tissues(tis),brand_name(bra),box_id(0),price(0.0){};
    Tissue_box(int tis, string bra, int box):tissues(tis),brand_name(bra),box_id(box),price(0.0){cout<<bra<<" company produced "<<tis<<" tissues in box "<<box<<"."<<endl;};
    Tissue_box(int tis, string bra, int box, float pri):tissues(tis),brand_name(bra),box_id(box),price(pri){};
    Tissue_box(Tissue_box & old_box){tissues = old_box.tissues; brand_name = old_box.brand_name; box_id= old_box.box_id; price = old_box.price;};
};


int main()
{
    Tissue_box box1;
    Tissue_box box2(200, "Janchust");
    Tissue_box box3(180, "Globchust", 127342);
    Tissue_box box4(240, "National tissues",2787347,3.99f);
    Tissue_box box5 = box2;
    return 0;
}
