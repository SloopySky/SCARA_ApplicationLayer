#include <unity.h>
#include <StepMotorType.h>
#include <IGpioType.h>
#include <IOneShotTimerType.h>

#define DEG_IN_STEP_X100    45

static void MoveTest(void);

void setUp(void) { }
void tearDown(void) { }

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(MoveTest);
    return UNITY_END();
}

static void MoveTest(void)
{
    struct {
        uint16_t rpm;
        fp32x100_t angularDisplacement;
        uint32_t expectedSteps;
        uint32_t expectedCycleTime;
    } testData = {
        .rpm = 30,
        .angularDisplacement = 86422,
        .expectedSteps = 1920,
        .expectedCycleTime = 1250,
    };

    Gpio_t gpio;
    OneShotTimer_t squareWaveTimer;

    StepMotor_t stepMotor;
    StepMotorInit_t cfg = {
        .degPerStep = DEG_IN_STEP_X100,
        .enableGpio = &gpio,
        .stepGpio = &gpio,
        .dirGpio = &gpio,
        .squareWaveTimer = &squareWaveTimer,
    };
    StepMotor_Initialize(&stepMotor, &cfg);

    StepMotor_Move(&stepMotor, testData.rpm, testData.angularDisplacement);

    TEST_ASSERT_EQUAL(testData.expectedSteps, stepMotor.steps);
}
