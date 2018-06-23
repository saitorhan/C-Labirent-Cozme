# C-Labirent-Cozme
C ile yazılmış bir labirent çözme uygulamasıdır.

1) Rastgele Labirent Üretimi
Rastgele labirent üretimi için öncelikle dizilerin atanmayan elemana otomatik olarak 0 değerini atama özelliğinden dolayı tamamen duvardan oluşan bir alan oluşturulur. Alan oluşturulduktan sonra yol garantili 3 giriş için rastgele 3 tane "x" değeri  (x,0) değeri belirlenir. Bu "x" değerleri belirlendikten sonra çıkışın olması istenen y=29 sütununa gelininceye kadar rastgele yön belirlenip, belirlenen yöne bir adım atılıp, gidilen yerin değeri "0" (yol) olarak atanır. Yol çizimi tamamlandıktan sonra geriye kalan değerler bir döngü yardımıyla rastgele 0 veya 1'e atanır.

2) Labirenti Çözme ve Yol Yazdırma
	Öncelikle bir döngü yardımıyla çıkışın bulunduğu y=29 sütunundaki her 0 değeri ÇIKIŞ noktası olarak işaretler. Daha sonra ikinci bir döngü yardımıyla girişin bulunduğu y=0 sütunundaki her bir 0 değerinden giriş yapar. Sürekli olarak etrafında 0 değerinin olup olmadığını kontrol eder ve varsa etrafında 0 değeri o değerler için de recursive olarak çözüm fonksiyonunu çağırır. Etrafında yol olmaması durumunda ise gelinen yön tarafına bir adım geri dönüp, dönüş yapmadan bulunduğu yeri de GİDİLDİ olarak işaretler. Bu şekilde ÇIKIŞ değerini buluncaya veya başladığı noktaya tekrar dönünceya kadar işlemler devam eder. ÇIKIŞ noktasına varması durumunda labirent çözülmüştür, başladığı noktaya dönerse labirentte çıkış yolu bulamamıştır. Gidilen yolun yazdırılması içinde çözüm fonksiyonu her çağrıldığında ve dönen değer TRUE ise  gidilen yol (( i, j ) ikilisi) ve yön ekrana yazdırır.
	Her bir giriş için bu işlem yapıldıktan sonra bir sonraki giriş noktasına geçilmeden önce GİDİLDİ olarak işaretlenen yerleri eski haline getirmek amacıyla labirenti bir döngü yardımıyla tarayıp GİDİLDİ olarak işaretlenen yerlere 0 değeri atanır.