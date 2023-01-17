#ifndef EZMOT_H_INCLUDED
#define EZMOT_H_INCLUDED

namespace ezmot {

template <class MbedPwmDriver>
class EasyMotor {
public:
	EasyMotor(PinName pin1, PinName pin2, std::chrono::microseconds period)
		: pwm1_(pin1), pwm2_(pin2)
	{
		pwm1_.period_us(period.count());
		pwm2_.period_us(period.count());

		set_duty(0.f);
	}

	void set_duty(float duty) {
		float abs_duty = std::abs(duty);
		if (duty > 0) {
			pwm1_.write(abs_duty);
			pwm2_.write(0.f);
		} else {
			pwm1_.write(0.f);
			pwm2_.write(abs_duty);
		}
	}

	MbedPwmDriver &pwm1() {
		return pwm1_;
	}

	MbedPwmDriver &pwm2() {
		return pwm2_;
	}

private:
	MbedPwmDriver pwm1_, pwm2_;
};

}

#endif
