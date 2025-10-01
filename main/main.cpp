import XA;
import XB;

int main() {
	auto z1 = XA::Z{};
	auto z2 = XB::Z{};
	z1.add();
	z2.add();
	auto sum = z1.i + z2.i;
	return sum;
}

