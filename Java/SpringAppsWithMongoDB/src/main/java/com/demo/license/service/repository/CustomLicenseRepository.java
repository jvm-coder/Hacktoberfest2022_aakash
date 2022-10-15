package com.demo.license.service.repository;

import com.demo.license.service.model.License;

public interface CustomLicenseRepository {
    License partialUpdate(final String licenseKey, final String fieldName, Object fieldValue);

}
