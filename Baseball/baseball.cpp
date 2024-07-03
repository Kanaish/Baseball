#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) {

	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number.");
		}
	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		int strikes = 0;
		int balls = 0;

		if (question == guessNumber)
			return { true, 3, 0 };

		for (int i = 0; i < 3; ++i) {
			if (question[i] == guessNumber[i]) {
				strikes++;
			}
			else {
				for (int j = 0; j < 3; ++j) {
					if (i == j) continue;
					if (question[i] == guessNumber[j]) {
						balls++;
					}
				}
			}
		}

		return { false, strikes, balls };
	}

private:
	string question;
};