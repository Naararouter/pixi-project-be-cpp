CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

CREATE TABLE users (
   id UUID DEFAULT uuid_generate_v4() PRIMARY KEY,
   email VARCHAR(255) UNIQUE NOT NULL,
   last_login TIMESTAMP,
   created_at TIMESTAMP DEFAULT current_timestamp
);

CREATE TABLE auth_providers (
    user_id UUID REFERENCES users(id),
    provider VARCHAR(50) NOT NULL,
    provider_id VARCHAR(255) NOT NULL,
    password VARCHAR(255),
    PRIMARY KEY (user_id, provider)
);
