#include "studentas.h"
#include <iomanip>

std::istream& Studentas::readStudent(std::istream& is) {
    std::string line;
    if (!std::getline(is, line)) return is;
    std::istringstream ss(line);
    ss >> vardas_ >> pavarde_;
    nd_.clear();
    int paz;
    while (ss >> paz) nd_.push_back(paz);

    if (!nd_.empty()) {
        egz_ = nd_.back();
        nd_.pop_back();
    }
    else {
        egz_ = 0;
    }
    skaiciuotiGalutinius();
    return is;
}

double Studentas::skaiciuotiVidurki() const {
    if (nd_.empty()) return 0.0;
    double sum = 0;
    for (int n : nd_) sum += n;
    return sum / nd_.size();
}

double Studentas::skaiciuotiMediana() const {
    if (nd_.empty()) return 0.0;
    std::vector<int> temp = nd_;
    std::sort(temp.begin(), temp.end());
    int n = static_cast<int>(temp.size());
    if (n % 2 == 0)
        return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
    else
        return temp[n / 2];
}

void Studentas::skaiciuotiGalutinius() {
    gal_vid_ = skaiciuotiVidurki() * 0.4 + egz_ * 0.6;
    gal_med_ = skaiciuotiMediana() * 0.4 + egz_ * 0.6;
}
