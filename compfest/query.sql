SELECT a.id, a.tanggal, a.lokasi_dominan, b.divisi
FROM catatan_lokasi AS a
INNER JOIN data_profil AS b ON a.id = b.id
WHERE lokasi_dominan NOT IN (" Jakarta Pusat"
," Kabupaten Bogor"
," Kota Tangerang"
," Kota Bogor"
," Kota Depok"
," Jakarta Timur"
," Kota Bekasi"
," Jakarta Selatan"
," Jakarta Utara"
," Jakarta Barat"
," Kabupaten Tangerang"
," Kabupaten Bekasi"
," Kota Tangerang Selatan")
GROUP BY a.id
ORDER BY b.divisi;

SELECT COUNT(id), divisi
FROM data_profil
GROUP BY divisi;

SELECT *
FROM catatan_lokasi
WHERE (tanggal = "2019-05-30") AND lokasi_dominan NOT IN (" Jakarta Pusat"
," Kabupaten Bogor"
," Kota Tangerang"
," Kota Bogor"
," Kota Depok"
," Jakarta Timur"
," Kota Bekasi"
," Jakarta Selatan"
," Jakarta Utara"
," Jakarta Barat"
," Kabupaten Tangerang"
," Kabupaten Bekasi"
," Kota Tangerang Selatan");

SELECT *
FROM catatan_lokasi
WHERE tanggal = "2019-06-08" AND lokasi_dominan IN (" Jakarta Pusat"
," Kabupaten Bogor"
," Kota Tangerang"
," Kota Bogor"
," Kota Depok"
," Jakarta Timur"
," Kota Bekasi"
," Jakarta Selatan"
," Jakarta Utara"
," Jakarta Barat"
," Kabupaten Tangerang"
," Kabupaten Bekasi"
," Kota Tangerang Selatan");

SELECT a.id, a.tanggal, a.lokasi_dominan, b.divisi
FROM catatan_lokasi AS a
INNER JOIN data_profil AS b ON a.id = b.id
WHERE lokasi_dominan NOT IN (" Jakarta Pusat"
," Kabupaten Bogor"
," Kota Tangerang"
," Kota Bogor"
," Kota Depok"
," Jakarta Timur"
," Kota Bekasi"
," Jakarta Selatan"
," Jakarta Utara"
," Jakarta Barat"
," Kabupaten Tangerang"
," Kabupaten Bekasi"
," Kota Tangerang Selatan") AND lokasi_dominan IN (" Kota Yogyakarta", " Kabupaten Bantul", " Kabupaten Sleman")
GROUP BY a.id
ORDER BY a.lokasi_dominan;

SELECT a.id, a.tanggal, a.lokasi_dominan, b.divisi
FROM catatan_lokasi AS a
INNER JOIN data_profil AS b ON a.id = b.id
WHERE lokasi_dominan NOT IN (" Jakarta Pusat"
," Kabupaten Bogor"
," Kota Tangerang"
," Kota Bogor"
," Kota Depok"
," Jakarta Timur"
," Kota Bekasi"
," Jakarta Selatan"
," Jakarta Utara"
," Jakarta Barat"
," Kabupaten Tangerang"
," Kabupaten Bekasi"
," Kota Tangerang Selatan") AND lokasi_dominan IN (" Kota Medan")
GROUP BY a.id
ORDER BY a.lokasi_dominan;

SELECT a.id, a.tanggal, a.lokasi_dominan, b.divisi
FROM catatan_lokasi AS a
INNER JOIN data_profil AS b ON a.id = b.id
WHERE lokasi_dominan NOT IN (" Jakarta Pusat"
," Kabupaten Bogor"
," Kota Tangerang"
," Kota Bogor"
," Kota Depok"
," Jakarta Timur"
," Kota Bekasi"
," Jakarta Selatan"
," Jakarta Utara"
," Jakarta Barat"
," Kabupaten Tangerang"
," Kabupaten Bekasi"
," Kota Tangerang Selatan")
GROUP BY a.id
ORDER BY a.lokasi_dominan;

SELECT count(a.id), a.tanggal
FROM catatan_lokasi AS a
INNER JOIN data_profil AS b ON a.id = b.id
WHERE lokasi_dominan IN (" Jakarta Pusat"
," Kabupaten Bogor"
," Kota Tangerang"
," Kota Bogor"
," Kota Depok"
," Jakarta Timur"
," Kota Bekasi"
," Jakarta Selatan"
," Jakarta Utara"
," Jakarta Barat"
," Kabupaten Tangerang"
," Kabupaten Bekasi"
," Kota Tangerang Selatan")
GROUP BY a.tanggal;

SELECT count(a.id), a.tanggal
FROM catatan_lokasi AS a
INNER JOIN data_profil AS b ON a.id = b.id
WHERE b.divisi = "Customer Service" AND lokasi_dominan NOT IN (" Jakarta Pusat"
," Kabupaten Bogor"
," Kota Tangerang"
," Kota Bogor"
," Kota Depok"
," Jakarta Timur"
," Kota Bekasi"
," Jakarta Selatan"
," Jakarta Utara"
," Jakarta Barat"
," Kabupaten Tangerang"
," Kabupaten Bekasi"
," Kota Tangerang Selatan")
GROUP BY a.tanggal;