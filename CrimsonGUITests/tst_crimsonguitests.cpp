#define TESTMODE

#include <QtTest/QTest>
#include <QCoreApplication>
#include <QSignalSpy>
#include "crimson.h"

// add necessary includes here

class CrimsonGUITests : public QObject
{
    Q_OBJECT

public:
    CrimsonGUITests();
    ~CrimsonGUITests();

private:
    Crimson crimson;

private slots:
    void test_presetSaveAndChange();
    FxBank setRandomBankValues();
    int randonNumber(int low, int hight);
    bool randomBool();

};

CrimsonGUITests::CrimsonGUITests()
{

}

CrimsonGUITests::~CrimsonGUITests()
{

}

void CrimsonGUITests::test_presetSaveAndChange()
{   int presetA = 1;
    int presetB = 2;

    // Set up and save a preset with random numbers
    crimson.fxBank.preset = presetA;
    FxBank fxBank = setRandomBankValues();
    crimson.slot_fx_preset_saved();

    // Change fxBank parameters randomly
    crimson.fxBank.preset = presetB;
    setRandomBankValues();

    // Load previous conf
    crimson.slot_bank_preset_changed(presetA);

    // Assert
    QCOMPARE(crimson.fxBank.preset, presetA);

    for (int i = 0; i < MAXEFFECTS; i++)
    {
        for (int k = 0; k < fxBank.fx[i].nParam; k++)
        {
            QCOMPARE(crimson.fxBank.fx[i].state, fxBank.fx[i].state);
            QCOMPARE(crimson.fxBank.fx[i].param[k].value, fxBank.fx[i].param[k].value);
            qDebug() << "Correctly loaded: " << crimson.fxBank.fx[i].name << ", " << crimson.fxBank.fx[i].param[k].name;
        }
    }
}

FxBank CrimsonGUITests::setRandomBankValues()
{
    FxBank fxBank;
    for (int i = 0; i < MAXEFFECTS; i++)
    {
        for (int k = 0; k < fxBank.fx[i].nParam; k++)
        {
            bool state = randomBool();
            fxBank.fx[i].state = state;
            crimson.fxBank.fx[i].state = state;

            int number = randonNumber(0,99);
            fxBank.fx[i].param[k].value = number;
            crimson.fxBank.fx[i].param[k].value = number;
        }
    }

    return fxBank;
}

int CrimsonGUITests::randonNumber(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}

bool CrimsonGUITests::randomBool()
{
    return rand() > 0.5;
}

QTEST_MAIN(CrimsonGUITests)

#include "tst_crimsonguitests.moc"
