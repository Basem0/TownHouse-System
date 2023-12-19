package com.zkrallah.z_fire.di

import com.google.firebase.database.FirebaseDatabase
import com.zkrallah.z_fire.data.repositories.MainRepositoryImpl
import com.zkrallah.z_fire.domain.repositories.MainRepository
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.components.SingletonComponent
import javax.inject.Singleton

@Module
@InstallIn(SingletonComponent::class)
object RepositoriesModule {

    @Provides
    @Singleton
    fun provideMainRepository(
        database: FirebaseDatabase
    ): MainRepository {
        return MainRepositoryImpl(database)
    }
}