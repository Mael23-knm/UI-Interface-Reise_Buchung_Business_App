
#include "check.h"
#include <QMessageBox>

Check::Check(std::shared_ptr<TravelAgency> travelagency): travelagency(travelagency)
{

}

bool Check:: checkTravelsDisjunct(QString& message){
    for (const std::shared_ptr<Customer>& customer : travelagency->getCustomers()) {
        const std::vector<std::shared_ptr<Travel>>& travels = customer->getTravelList();

        for (size_t i = 0; i < travels.size(); ++i) {
            for (size_t j = i + 1; j < travels.size(); ++j) {

                if (travels[i]->überlappen(travels[j])) {
                    // Zeitliche Überlappung gefunden
                    message = "Die Reisen des Kunden " + QString::fromStdString(customer->getCustomerFirstname() + " " + customer->getCustomerLastname()) +
                              " (Reise " + QString::number(travels[i]->getId()) + " und Reise " + QString::number(travels[j]->getId()+1) + ") überlappen sich.";
                   // QMessageBox::information(nullptr, "Fehler bei der Konsistenzprüfung", message);
                              return false;
                }
            }
        }
    }

    // Keine Überlappung gefunden
    return true;
}

bool Check::operator()()
{
    QString message;
    // Hier können weitere Prüfungen hinzugefügt werden
    bool result = true;

        if (!checkTravelsDisjunct(message)) {
            QMessageBox::information(nullptr, "Fehler bei der Konsistenzprüfung", message);
            result = false;
        }

    return result;
}
