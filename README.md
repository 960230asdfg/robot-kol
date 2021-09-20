# robot-kol


## Nasıl yaptım:
İlk olarak robot kol için tasarlanmış ağaçtan parçaları alıp onların montajını yaptım ve servo motorları taktım. Bauhaus’dan babmla bir sunta kestirip kolu olun üzerine taktım. 
Sonra servo bağlantıları için Arduino UNO’ya uygun bir shield tasarladım. Daha sonra delikli partinaks ve headerları kullanarak havya ve lehim ile bu shieldı ürettim (sarı renkli parça). İki adet joystick modülü kullanarak bir kumanda yaptım ve bir kabloyla shieldıma bağladım. 
Daha sonra Arduino UNO üzerinde çalışacak kodu kendim yazdım. Ama takıldığım bazı yerlerde babamdan da yardım aldım. Bütün montaj ve lehimleme işlerini kendim yaptım. Bu proje sayesinde yazılım, elektronik ve mekanik bilgilerimi de geliştirmiş oldum. 


## Nasıl kullanılıyor:
Kumandanın sol joystiğini yukarı aşağı itince kol yukarı aşağı hareket ediyor. Sola sağa itince de ucundaki el açılıp kapanıyor. 
Kumandanın sağ joystiğini yukarı aşağı itince kolun açısı değişiyor. Sola sağa itince de kol sağa sola dönüş yapıyor.  

**Kullanımı kolay olsun diye şu özellikleri de ekledim: **
- Sağ taraftaki joystick ile ayarladığınız dönüş pozisyonunu sabitlemek için sol joystiğe bir kere bastırıyorsunuz. 
- Sağ taraftaki joystick ile ayarladığınız açı pozisyonunu sabitlemek için sol joystiğe iki kere bastırıyorsunuz.
- Sol taraftaki joystick ile ayarladığınız el pozisyonunu sabitlemek için sağ joystiğe bir kere bastırıyorsunuz.
- Sol taraftaki joystick ile ayarladığınız yükseklik pozisyonunu sabitlemek için sağ joystiğe iki kere bastırıyorsunuz.
- Sol joystiğe 1 saniye basılı tutunca sabitlediğiniz pozisyonlar temizleniyor. 
- Sağ joystiğe 1 saniye basılı tutunca lamba açılıp kapanıyor. 
