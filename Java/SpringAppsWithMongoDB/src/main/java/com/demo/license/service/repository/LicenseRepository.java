package com.demo.license.service.repository;

import com.demo.license.service.model.License;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.data.mongodb.repository.Query;
import org.springframework.stereotype.Repository;

@Repository
public interface LicenseRepository extends MongoRepository<License, String>, CustomLicenseRepository {

    @Query("{'licenseKey': ?0 }")
    License findLicensesByLicenseKey(String licenseKey);

}
