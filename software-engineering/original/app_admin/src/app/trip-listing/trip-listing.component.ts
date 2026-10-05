import { Component, OnInit } from '@angular/core';
import { CommonModule } from '@angular/common';
import { TripCardComponent } from '../trip-card/trip-card.component';
import { Trip } from '../models/trip';
import { TripDataService } from '../trip-data.service';
import { RouterModule } from '@angular/router';
import { AuthenticationService } from '../authentication.service';

@Component({
  selector: 'app-trip-listing',
  standalone: true,
  imports: [CommonModule, TripCardComponent, RouterModule],
  templateUrl: './trip-listing.component.html',
  styleUrl: './trip-listing.component.css'
})
export class TripListingComponent implements OnInit {
  trips: Trip[] = [];

  constructor(
    private tripDataService: TripDataService,
    public authService: AuthenticationService
  ) {}

  ngOnInit(): void {
    this.tripDataService.getTrips().subscribe({
      next: (data) => {
        this.trips = data;
      },
      error: (err) => {
        console.error('Error retrieving trips:', err);
      }
    });
  }
}