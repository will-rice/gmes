#ifndef PW_MATERIAL_HH_
#define PW_MATERIAL_HH_

#include <stdexcept>

namespace gmes {
template<class T> class PwMaterial {
public:
	// constructors & destructor
	PwMaterial(const int * const idx, int size)
	{
		if (size != 3)
		{
			throw std::domain_error("length of the array index must be 3.");
		}
		else
		{
			i = idx[0];
			j = idx[1];
			k = idx[2];
		}
	}

	virtual ~PwMaterial() {
	}

	size_t get_i() const {
		return i;
	}
	size_t get_j() const {
		return j;
	}
	size_t get_k() const {
		return k;
	}
	void set_i(size_t i) {
		this->i = i;
	}
	void set_j(size_t j) {
		this->j = j;
	}
	void set_k(size_t k) {
		this->k = k;
	}

	virtual void
	update(T * const inplace_field, int inplace_dim1, int inplace_dim2, int inplace_dim3,
			const T * const in_field1, int in1_dim1, int in1_dim2, int in1_dim3,
			const T * const in_field2, int in2_dim1, int in2_dim2, int in2_dim3,
			double d1, double d2, double dt, double n) = 0;

protected:
	size_t i, j, k;
};

template <typename T> class MaterialElectric: public PwMaterial<T> {
public:
	MaterialElectric(const int * const idx, int size) :
		PwMaterial<T>(idx, size) {
	}
	virtual ~MaterialElectric() {
	}

	virtual double get_epsilon() const = 0;
	virtual void set_epsilon(double epsilon) = 0;
};

template <typename T> class MaterialMagnetic: public PwMaterial<T> {
public:
	MaterialMagnetic(const int * const idx, int size) :
		PwMaterial<T>(idx, size) {
	}
	virtual ~MaterialMagnetic() {
	}

	virtual double get_mu() const = 0;
	virtual void set_mu(double mu) = 0;
};

}

#endif /*PW_MATERIAL_HH_*/
