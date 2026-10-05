import { Inject, Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Trip } from './models/trip';
import { User } from './models/user';
import { AuthResponse } from './models/auth-response';
import { BROWSER_STORAGE } from './storage';

@Injectable({
  providedIn: 'root'
})
export class TripDataService {
  private apiBaseUrl = 'http://localhost:3000/api/trips';
  private authBaseUrl = 'http://localhost:3000/api';

  constructor(
    private http: HttpClient,
    @Inject(BROWSER_STORAGE) private storage: Storage
  ) {}

  private getAuthHeaders(): HttpHeaders {
    const token = this.storage.getItem('travlr-token');
    return new HttpHeaders({
      Authorization: `Bearer ${token ? token : ''}`,
      'Content-Type': 'application/json'
    });
  }

  getTrips(): Observable<Trip[]> {
    return this.http.get<Trip[]>(this.apiBaseUrl);
  }

  getTrip(code: string): Observable<Trip> {
    return this.http.get<Trip>(`${this.apiBaseUrl}/${code}`);
  }

  addTrip(trip: Trip): Observable<Trip> {
    return this.http.post<Trip>(this.apiBaseUrl, trip, {
      headers: this.getAuthHeaders()
    });
  }

  updateTrip(code: string, trip: Trip): Observable<Trip> {
    return this.http.put<Trip>(`${this.apiBaseUrl}/${code}`, trip, {
      headers: this.getAuthHeaders()
    });
  }

  register(user: User, password: string): Observable<AuthResponse> {
    const formData = {
      name: user.name,
      email: user.email,
      password: password
    };

    return this.http.post<AuthResponse>(`${this.authBaseUrl}/register`, formData);
  }

  login(user: User, password: string): Observable<AuthResponse> {
    const formData = {
      email: user.email,
      password: password
    };

    return this.http.post<AuthResponse>(`${this.authBaseUrl}/login`, formData);
  }
}