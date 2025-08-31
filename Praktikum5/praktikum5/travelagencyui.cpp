#include "travelagencyui.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include "trainticket.h"
#include "ui_travelagencyui.h"
#include "booking.h"
#include "travelagency.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QObject>


TravelAgencyUI::TravelAgencyUI(std::shared_ptr<TravelAgency> travelagency, QWidget *parent) :
    QMainWindow(parent),
    travelagency(travelagency),
    ui(new Ui::TravelAgencyUI),
    check(travelagency)

{
    ui->setupUi(this);
    ui->groupBox_Kunde->setHidden(true);
    ui->groupBox_Reise->setHidden(true);



}

TravelAgencyUI::~TravelAgencyUI()
{
    delete ui;
}

void TravelAgencyUI::on_actionDatei_einlesen_triggered()
{
    bool laufzeit = true;

    //QString fileName = QFileDialog::getOpenFileName(this,"Open JSON File", "E:/PRAKTIKA PG2/neu2Praktikum3/newPraktikum3");
    QString fileName = QFileDialog::getOpenFileName(this, "Open JSON File","", "JSON Files (*.json)");
    while(laufzeit){
        if(!fileName.isEmpty()){

            try{

                travelagency->readFile(fileName);

                QString message = "Es wurden " + QString::number(travelagency->getFlight()) + " Flugreservierungen, "+
                                  QString::number(travelagency->getHotel()) + " Hotelbuchungen , "+
                                  QString::number(travelagency->getCar()) + " Mietwagenreservierungen und " +
                                  QString::number(travelagency->getTrain())+ " Zugbuchungen im Gesamtwert von "+
                                  QString::number(travelagency->getSumme()) + " Euro eingelesen.\n"+
                                  "Es wurden " + QString::number(travelagency->getTravels().size()) + " Reisen und " +
                                  QString::number(travelagency->getCustomers().size()) + " Kunden angelegt.\n";

                std::shared_ptr<Customer> customerId1 = travelagency->findCustomer(1);
                QString message2, message3;
                if (customerId1) {
                    QString messageX = "Der Kunde mit der ID 1 hat " + QString::number(customerId1->getTravelList().size()) + " Reisen gebucht.\n";
                    message2 = messageX;
                }
                std::shared_ptr<Travel> travelId17 = travelagency->findTravel(17);
                if (travelId17) {
                    QString messageY = "Zur Reise mit der ID 17 gehören " + QString::number(travelId17->getTravelBookings().size()) + " Buchungen.\n";
                    message3 = messageY;
                }

                // Konsistenzprüfung durchführen

               /* QString errorMessage;
                if (!check.checkTravelsDisjunct(errorMessage)) {
                    // Fehlermeldung anzeigen
                    QMessageBox::information(this, "Fehler bei der Konsistenzprüfung", errorMessage);
                        //return;  // Verlassen der Funktion bei einem Fehler
                }
                */

                ui->statusbar->showMessage("Datei erfolgreich gelesen!",5000);
                QMessageBox:: about(this, "Datei erfolgreich eingelesen",message + message2 + message3);
                laufzeit = false;

            }catch(const std::invalid_argument& err){
                //BookingsVonListWidget();
                QMessageBox msgBox;
                msgBox.setWindowTitle("Fehler beim Einlesen der Buchungen");
                msgBox.setText(err.what());
                msgBox.setInformativeText("Das Einlesen der Buchungen wurde in der betroffenen Zeile "
                                          "gestoppt. Die vorhangehenden Buchungen wurden erfolgreich angelegt.");
                msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Discard | QMessageBox::Cancel);
                msgBox.setDefaultButton(QMessageBox::Retry);
                msgBox.setDetailedText("Wenn Sie die Datei bereits korrigiert haben, wählen Sie 'Retry'."
                                       "Wählen Sie 'Discard', um alle Buchungen zu löschen und 'Cancel', um die"
                                       "vorhandenen Buchungen stehenzulassen und diesen Dialog zu verlassen." );
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.exec();

                int result = msgBox.exec();

                if(result == QMessageBox::Retry ){
                    continue;
                }else if(result == QMessageBox::Discard){
                    //deleteBookings();

                    laufzeit = false;
                }else if(result == QMessageBox::Cancel){
                    laufzeit = false;
                }


            }catch (const std::exception& e) {
                std::cerr << "Exception caught: " << e.what() << std::endl;
                 // oder eine andere sinnvolle Rückgabewert
            }catch(...){

                //QMessageBox::critical(this,"Fehler bei dem Preis","Ungueltiger Preis");
                laufzeit = false;
            }
        }
    }

}



void TravelAgencyUI::on_action_iatacodes_einlesen_triggered()
{
    bool laufzeit = true;

    QString fileName = QFileDialog::getOpenFileName(this, "Open JSON File","", "JSON Files (*.json)");
    while(laufzeit){
        if(!fileName.isEmpty()){

            try {
                travelagency->iatacodeFile(fileName);
                QMessageBox::information(this, "Lesen von iatacodes", " Datei iatacodes erfolgreich gelesen");
                 laufzeit = false;
            } catch (const std::invalid_argument& err) {
                QMessageBox::critical(this, "Fehler beim Lesen von iatacodes", err.what());
                laufzeit = false;
            }catch(...){
                laufzeit = false;
            }

        }
    }

}




void TravelAgencyUI::on_actionSuche_triggered()
{
    long customerId = QInputDialog::getInt(this,"Kund*innen","ID");
    std::shared_ptr<Customer> customer = travelagency->findCustomer(customerId);
    if (customer) {
        // Display customer information
        ui->groupBox_Kunde->setHidden(false);
        std::string id = std::to_string(customerId);
        QString customerName = QString::fromStdString(customer->getCustomerFirstname() + " " + customer->getCustomerLastname());
        ui->lineEdit_ID->setText(QString::fromStdString(id));
        ui->lineEdit_Name->setText(customerName);

        // Clear existing rows in the table
        ui->tableWidget_Reisen->clearContents();
        ui->tableWidget_Reisen->setRowCount(0);

        int row = 0;
        for (const std::shared_ptr<Travel> &travel : customer->getTravelList()) {
            QTableWidgetItem* idItem = new QTableWidgetItem();
            idItem->setText(QString::number(travel->getId()));

            QString formatted_startDateItem = QLocale("de_DE").toString(QDateTime::fromString(QString::fromStdString(getTravel_EarliestStartDate(travel)), "yyyyMMdd"), "dddd, d.MMMM yyyy");
            QString formatted_endeDateItem = QLocale("de_DE").toString(QDateTime::fromString(QString::fromStdString(getTravel_LatestEndDate(travel)), "yyyyMMdd"), "dddd, d.MMMM yyyy");


            QTableWidgetItem* startDateWidget = new QTableWidgetItem(formatted_startDateItem);
            QTableWidgetItem* endeDateWidget = new QTableWidgetItem(formatted_endeDateItem);

            ui->tableWidget_Reisen->insertRow(row);
            ui->tableWidget_Reisen->setItem(row, 0, idItem);
            ui->tableWidget_Reisen->setItem(row, 1, startDateWidget);
            ui->tableWidget_Reisen->setItem(row, 2, endeDateWidget);
            ui->tableWidget_Reisen->setColumnWidth(0, 80);
            ui->tableWidget_Reisen->setColumnWidth(1, 160);
            ui->tableWidget_Reisen->setColumnWidth(2, 160);
            row++;
        }

        ui->statusbar->clearMessage();
    } else {
        ui->statusbar->showMessage("Kein Kunde mit dieser ID ist vorhanden!", 5000);
    }


}

void TravelAgencyUI::on_actionSpeichern_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save JSON File", "", "JSON Files (*.json)");

    if (!fileName.isEmpty()) {
        try {
            travelagency->writeFile(fileName);
            ui->statusbar->showMessage("Datei erfolgreich gespeichert!", 5000);
        } catch (const std::exception& e) {
            std::cerr << "Fehler beim Speichern der Datei: " << e.what() << std::endl;
            ui->statusbar->showMessage("Fehler beim Speichern der Datei!", 5000);
        }
    }
}

std::string TravelAgencyUI::getTravel_EarliestStartDate(const std::shared_ptr<Travel> travel) const
{
    std::string earliestDate = "";
    for (const std::shared_ptr<Booking> &booking : travel->getTravelBookings()) {
        std::string fromDate = booking->getFromDate();
        if (earliestDate.empty() || fromDate < earliestDate) {
            earliestDate = fromDate;
        }
    }
    return earliestDate;
}


std::string TravelAgencyUI::getTravel_LatestEndDate(const std::shared_ptr<Travel> travel) const
{
    std::string latestDate = "";
    for (const std::shared_ptr<Booking> &booking : travel->getTravelBookings()) {
        std::string toDate = booking->getToDate();
        if (latestDate.empty() || toDate > latestDate) {
            latestDate = toDate;
        }
    }
    return latestDate;
}


void TravelAgencyUI::on_tableWidget_Reisen_cellDoubleClicked(int row, int column)
{
    ui->groupBox_Reise->setHidden(false);
    QTableWidgetItem* idItem = ui->tableWidget_Reisen->item(row, column);
    if (idItem) {
        long travelId = idItem->text().toLong();
        std::shared_ptr<Travel> selectedTravel = travelagency->findTravel(travelId);

        if (selectedTravel) {
            ui->tableWidget_Buchungen->clearContents();
            ui->tableWidget_Buchungen->setRowCount(0);

            /*std::vector<std::shared_ptr<Booking>> sortedBookings = selectedTravel->getTravelBookings();
            std::sort(sortedBookings.begin(), sortedBookings.end(), [](const std::shared_ptr<Booking> a, const std::shared_ptr<Booking> b) {
                QDate startDateA = QDate::fromString(QString::fromStdString(a->getFromDate()), "yyyyMMdd");
                QDate startDateB = QDate::fromString(QString::fromStdString(b->getFromDate()), "yyyyMMdd");
                return startDateA < startDateB;
            });
            */


            int row = 0;

            for (const std::shared_ptr<Booking> &booking : selectedTravel->getTravelBookings()) {

                buchungen = selectedTravel->getTravelBookings();
                // Create an icon based on the booking type (Flight, RentalCar, Hotel, Train)
                QIcon bookingIcon;
               // QString type;
                // showMap(booking);
                if (const std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking)) {
                    bookingIcon = QIcon("flight.png");
                    showFlightOnMap(flightBooking);

                } else if (const std::shared_ptr<RentalCarReservation> rentalCarBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
                    bookingIcon = QIcon("car.jpg");
                    showRentalCarOnMap(rentalCarBooking);

                } else if (const std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking)) {
                    bookingIcon = QIcon("hotel.jpg");
                    showHotelOnMap(hotelBooking);

                } else if (const std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking)) {
                    bookingIcon = QIcon("train.jpg");
                    showTrainOnMap(trainBooking);

                }

                ui->lineEdit_ReiseID->setText(QString::fromStdString(std::to_string(selectedTravel->getId())));

                QTableWidgetItem* iconItem = new QTableWidgetItem(bookingIcon,"");

                QDate startDateItem = QDate::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd");
                QDate endDateItem = QDate::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd");

                QString deutscheStartDate = QLocale("de_DE").toString(startDateItem, "dddd, d.MMMM yyyy");
                QString deutscheEndDate = QLocale("de_DE").toString(endDateItem, "dddd, d.MMMM yyyy");

                QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(booking->getPrice()));
                QTableWidgetItem* startDateWidget = new QTableWidgetItem(deutscheStartDate);
                QTableWidgetItem* endeDateWidget = new QTableWidgetItem(deutscheEndDate);


                ui->tableWidget_Buchungen->insertRow(row);
                ui->tableWidget_Buchungen->setItem(row, 0, iconItem);

                ui->tableWidget_Buchungen->setItem(row, 1,startDateWidget);
                ui->tableWidget_Buchungen->setItem(row, 2,endeDateWidget );
                ui->tableWidget_Buchungen->setItem(row, 3, priceItem);
                ui->tableWidget_Buchungen->setColumnWidth(0, 80);
                ui->tableWidget_Buchungen->setColumnWidth(1, 160);
                ui->tableWidget_Buchungen->setColumnWidth(2, 160);

                row++;
            }
        }
    }

}


void TravelAgencyUI::on_tableWidget_Buchungen_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem* iconItem = ui->tableWidget_Reisen->item(row, column);
    std::shared_ptr<Booking> selectedBooking = nullptr;

    if (row >= 0 && row < buchungen.size()) {
        selectedBooking = buchungen[row];
    }

    if(iconItem && selectedBooking){
        buchungsdetails = std::make_shared<Buchungsdetails>(selectedBooking,this);
        buchungsdetails->setWindowTitle("Buchungsdetails");
        buchungsdetails->show();
         connect(buchungsdetails.get(), &Buchungsdetails::checkSignal, this, &TravelAgencyUI::slotCheck);
    }


}

void TravelAgencyUI::slotCheck()
{
    check() ;
}


void TravelAgencyUI::showFlightOnMap(const std::shared_ptr<FlightBooking>& flightBooking) {
    // Erstellen des GeoJSON-Codes für die Flugbuchung
    QJsonObject geoJson;
    geoJson["type"] = "Feature";

    // Erstellen der Linie (LineString) für die Flugstrecke
    QJsonObject geometry;
    geometry["type"] = "LineString";
    QJsonArray lineCoordinates;
    lineCoordinates.append(QJsonArray{ flightBooking->getFromDestLongitude(), flightBooking->getFromDestLatitude() });
    lineCoordinates.append(QJsonArray{ flightBooking->getToDestLongitude(), flightBooking->getToDestLatitude() });
    geometry["coordinates"] = lineCoordinates;

    geoJson["geometry"] = geometry;

    // Hinzufügen der Eigenschaften (Properties) für die Flugbuchung
    QJsonObject properties;
    properties["Flug"] = QString::fromStdString(flightBooking->getFromDestination() + " nach " + flightBooking->getToDestination());
    properties["FromAirport"] = QString::fromStdString(travelagency->getAirportMap()[flightBooking->getFromDestination()]->getName());
    properties["ToAirport"] = QString::fromStdString(travelagency->getAirportMap()[flightBooking->getToDestination()]->getName());

    geoJson["properties"] = properties;

    // Erzeugen der GeoJSON-URL
    QUrl geoJsonUrl("http://townsendjennings.com/geo/?geojson=" + QJsonDocument(geoJson).toJson());

    // Öffnen der GeoJSON-URL in einem Standard-Webbrowser
    QDesktopServices::openUrl(geoJsonUrl);
}

void TravelAgencyUI::showRentalCarOnMap(const std::shared_ptr<RentalCarReservation>& rentalCarBooking) {
    // Erstellen des GeoJSON-Codes für die Mietwagenbuchung
    QJsonObject geoJson;
    QJsonArray coordinates;

    // Überprüfen, ob Abhol- und Rückgabestation unterschiedlich sind
    if (rentalCarBooking->getPickupLocation() != rentalCarBooking->getReturnLocation()) {
        geoJson["type"] = "Feature";
        QJsonObject geometry;
        geometry["type"] = "LineString";
        coordinates.append(QJsonArray{ rentalCarBooking->getPickupLongitude(), rentalCarBooking->getPickupLatitude() });
        coordinates.append(QJsonArray{ rentalCarBooking->getReturnLongitude(), rentalCarBooking->getReturnLatitude() });
        geometry["coordinates"] = coordinates;
        geoJson["geometry"] = geometry;
    } else {
        geoJson["type"] = "Feature";
        QJsonObject geometry;
        geometry["type"] = "Point";
        coordinates.append(QJsonArray{ rentalCarBooking->getPickupLongitude(), rentalCarBooking->getPickupLatitude() });
        geometry["coordinates"] = coordinates;
        geoJson["geometry"] = geometry;
    }

    // Hinzufügen der Eigenschaften (Properties) für die Mietwagenbuchung
    QJsonObject properties;
    properties["Mietwagen"] = QString::fromStdString(rentalCarBooking->getPickupLocation() + " nach " + rentalCarBooking->getReturnLocation());
    properties["Station"] = QString::fromStdString(rentalCarBooking->getPickupLocation());
    properties["Firma"] = QString::fromStdString(rentalCarBooking->getCompany());

    geoJson["properties"] = properties;

    // Erzeugen der GeoJSON-URL
    QUrl geoJsonUrl("http://townsendjennings.com/geo/?geojson=" + QJsonDocument(geoJson).toJson());

    // Öffnen der GeoJSON-URL
    QDesktopServices::openUrl(geoJsonUrl);
}

void TravelAgencyUI::showHotelOnMap(const std::shared_ptr<HotelBooking>& hotelBooking) {
    // Erstellen des GeoJSON-Codes für die Hotelbuchung
    QJsonObject geoJson;
    geoJson["type"] = "Feature";

    QJsonObject geometry;
    geometry["type"] = "Point";
    QJsonArray coordinates;
    coordinates.append(hotelBooking->getHotelLongitude());
    coordinates.append(hotelBooking->getHotelLatitude());
    geometry["coordinates"] = coordinates;

    geoJson["geometry"] = geometry;

    // Hinzufügen der Eigenschaften (Properties) für die Hotelbuchung
    QJsonObject properties;
    properties["Hotel"] = QString::fromStdString(hotelBooking->getHotel());
    geoJson["properties"] = properties;

    // Erzeugen der GeoJSON-URL
    QUrl geoJsonUrl("http://townsendjennings.com/geo/?geojson=" + QJsonDocument(geoJson).toJson());

    // Öffnen der GeoJSON-URL
    QDesktopServices::openUrl(geoJsonUrl);
}

void TravelAgencyUI::showTrainOnMap(const std::shared_ptr<TrainTicket>& trainBooking) {
    // Erstellen des GeoJSON-Codes für die Zugbuchung
    QJsonObject geoJson;
    geoJson["type"] = "FeatureCollection";

    // Erstellen der Linie für die Zugstrecke
    QJsonObject feature;
    feature["type"] = "Feature";
    QJsonObject geometry;
    geometry["type"] = "LineString";
    QJsonArray lineCoordinates;

    // Hinzufügen der Startbahnhof-Koordinaten
    lineCoordinates.append(QJsonArray{ trainBooking->getFromStationLongitude(), trainBooking->getFromStationLatitude() });

    // Hinzufügen der Verbindungsbahnhof-Koordinaten
    for (const auto& connection : trainBooking->getConnectingsStations()) {
        QJsonDocument connectionDocument = QJsonDocument::fromJson(connection.c_str());
        QJsonObject connectionObject = connectionDocument.object();
        lineCoordinates.append(QJsonArray{ connectionObject["longitude"].toDouble(), connectionObject["latitude"].toDouble() });

        // Hinzufügen der Bahnhofsnamen zu den Eigenschaften (Properties)
        QJsonObject properties;
        properties["Bahnhof"] = connectionObject["name"].toString();
        feature["properties"] = properties;
    }

    // Hinzufügen der Zielbahnhof-Koordinaten
    lineCoordinates.append(QJsonArray{ trainBooking->getToStationLongitude(), trainBooking->getToStationLatitude() });

    geometry["coordinates"] = lineCoordinates;
    feature["geometry"] = geometry;

    // Fügen Sie das Feature der GeoJSON-Features-Liste hinzu
    QJsonArray featuresArray = geoJson["features"].toArray();
    featuresArray.append(feature);
    geoJson["features"] = featuresArray;

    // Erzeugen der GeoJSON-URL
    QUrl geoJsonUrl("http://townsendjennings.com/geo/?geojson=" + QJsonDocument(geoJson).toJson());

    // Öffnen der GeoJSON-URL
    QDesktopServices::openUrl(geoJsonUrl);
}

/*void TravelAgencyUI::showMap(const std::shared_ptr<Booking>& booking)
{
    // Erstellen des GeoJSON-Codes für die Zugbuchung
    QJsonObject geoJson;
    if (const std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking)) {

        geoJson["type"] = "Feature";

        // Erstellen der Linie (LineString) für die Flugstrecke
        QJsonObject geometry;
        geometry["type"] = "LineString";
        QJsonArray lineCoordinates;
        lineCoordinates.append(QJsonArray{ flightBooking->getFromDestLongitude(), flightBooking->getFromDestLatitude() });
        lineCoordinates.append(QJsonArray{ flightBooking->getToDestLongitude(), flightBooking->getToDestLatitude() });
        geometry["coordinates"] = lineCoordinates;

        geoJson["geometry"] = geometry;

        // Hinzufügen der Eigenschaften (Properties) für die Flugbuchung
        QJsonObject properties;
        properties["Flug"] = QString::fromStdString(flightBooking->getFromDestination() + " nach " + flightBooking->getToDestination());
        properties["FromAirport"] = QString::fromStdString(travelagency->getAirportMap()[flightBooking->getFromDestination()]->getName());
        properties["ToAirport"] = QString::fromStdString(travelagency->getAirportMap()[flightBooking->getToDestination()]->getName());

        geoJson["properties"] = properties;


    } else if (const std::shared_ptr<RentalCarReservation> rentalCarBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking)) {

        QJsonArray coordinates;

        // Überprüfen, ob Abhol- und Rückgabestation unterschiedlich sind
        if (rentalCarBooking->getPickupLocation() != rentalCarBooking->getReturnLocation()) {
            geoJson["type"] = "Feature";
            QJsonObject geometry;
            geometry["type"] = "LineString";
            coordinates.append(QJsonArray{ rentalCarBooking->getPickupLongitude(), rentalCarBooking->getPickupLatitude() });
            coordinates.append(QJsonArray{ rentalCarBooking->getReturnLongitude(), rentalCarBooking->getReturnLatitude() });
            geometry["coordinates"] = coordinates;
            geoJson["geometry"] = geometry;
        } else {
            geoJson["type"] = "Feature";
            QJsonObject geometry;
            geometry["type"] = "Point";
            coordinates.append(QJsonArray{ rentalCarBooking->getPickupLongitude(), rentalCarBooking->getPickupLatitude() });
            geometry["coordinates"] = coordinates;
            geoJson["geometry"] = geometry;
        }

        // Hinzufügen der Eigenschaften (Properties) für die Mietwagenbuchung
        QJsonObject properties;
        properties["Mietwagen"] = QString::fromStdString("Mietwagen von " + rentalCarBooking->getPickupLocation() + " nach " + rentalCarBooking->getReturnLocation());
        properties["Station"] = QString::fromStdString(rentalCarBooking->getPickupLocation());
        properties["Firma"] = QString::fromStdString(rentalCarBooking->getCompany());

        geoJson["properties"] = properties;


    } else if (const std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking)) {

        geoJson["type"] = "Feature";

        QJsonObject geometry;
        geometry["type"] = "Point";
        QJsonArray coordinates;
        coordinates.append(hotelBooking->getHotelLongitude());
        coordinates.append(hotelBooking->getHotelLatitude());
        geometry["coordinates"] = coordinates;

        geoJson["geometry"] = geometry;

        // Hinzufügen der Eigenschaften (Properties) für die Hotelbuchung
        QJsonObject properties;
        properties["Hotel"] = QString::fromStdString(hotelBooking->getHotel());
        geoJson["properties"] = properties;

    } else if (const std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking)) {

        geoJson["type"] = "FeatureCollection";

        // Erstellen der Linie für die Zugstrecke
        QJsonObject feature;
        feature["type"] = "Feature";
        QJsonObject geometry;
        geometry["type"] = "LineString";
        QJsonArray lineCoordinates;

        // Hinzufügen der Startbahnhof-Koordinaten
        lineCoordinates.append(QJsonArray{ trainBooking->getFromStationLongitude(), trainBooking->getFromStationLatitude() });

        // Hinzufügen der Verbindungsbahnhof-Koordinaten
        for (const auto& connection : trainBooking->getConnectingsStations()) {
            QJsonDocument connectionDocument = QJsonDocument::fromJson(connection.c_str());
            QJsonObject connectionObject = connectionDocument.object();
            lineCoordinates.append(QJsonArray{ connectionObject["longitude"].toDouble(), connectionObject["latitude"].toDouble() });

            // Hinzufügen der Bahnhofsnamen zu den Eigenschaften (Properties)
            QJsonObject properties;
            properties["Bahnhof"] = connectionObject["name"].toString();
            feature["properties"] = properties;
        }

        // Hinzufügen der Zielbahnhof-Koordinaten
        lineCoordinates.append(QJsonArray{ trainBooking->getToStationLongitude(), trainBooking->getToStationLatitude() });

        geometry["coordinates"] = lineCoordinates;
        feature["geometry"] = geometry;

        // Fügen Sie das Feature der GeoJSON-Features-Liste hinzu
        QJsonArray featuresArray = geoJson["features"].toArray();
        featuresArray.append(feature);
        geoJson["features"] = featuresArray;


    }

    // Erzeugen der GeoJSON-URL
    QUrl geoJsonUrl("http://townsendjennings.com/geo/?geojson=" + QJsonDocument(geoJson).toJson());

    // Öffnen der GeoJSON-URL
    QDesktopServices::openUrl(geoJsonUrl);

}
*/
